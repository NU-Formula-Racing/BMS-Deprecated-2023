#include "bms_telemetry.h"

void BMSTelemetry::InitializeCAN()
{
    hp_can_bus_.Initialize(ICAN::BaudRate::kBaud1M);
    vb_can_bus_.Initialize(ICAN::BaudRate::kBaud1M);
    lp_can_bus_.Initialize(ICAN::BaudRate::kBaud1M);

    InitializeVoltageAndTemperatureMessages();

    const uint32_t kTickPeriod{10};
    timer_group_.AddTimer(kTickPeriod, [this]() { this->TickHPCAN(); });
    timer_group_.AddTimer(kTickPeriod, [this]() { this->TickVBCAN(); });
    timer_group_.AddTimer(kTickPeriod, [this]() { this->TickLPCAN(); });
}

void BMSTelemetry::InitializeVoltageAndTemperatureMessages()
{
    AttachVoltageMessages(vb_can_bus_, voltage_messages_, kVoltageMessageTransmitPeriod);
    AttachTemperatureMessages(vb_can_bus_, temperature_messages_, kTemperatureMessageTransmitPeriod);
}

void BMSTelemetry::AttachVoltageMessages(ICAN &bus,
                                         std::array<CANTXMessage<7> *, kNumVoltageMessages> message_ptr_array,
                                         uint32_t transmit_period)
{
    for (uint16_t i = 0; i < kNumVoltageMessages; i++)
    {
        voltage_signals_[i * kSignalsPerMessage + 0] = new MakeUnsignedCANSignal(float, 0, 8, 0.012, 2);
        voltage_signals_[i * kSignalsPerMessage + 1] = new MakeUnsignedCANSignal(float, 8, 8, 0.012, 2);
        voltage_signals_[i * kSignalsPerMessage + 2] = new MakeUnsignedCANSignal(float, 16, 8, 0.012, 2);
        voltage_signals_[i * kSignalsPerMessage + 3] = new MakeUnsignedCANSignal(float, 24, 8, 0.012, 2);
        voltage_signals_[i * kSignalsPerMessage + 4] = new MakeUnsignedCANSignal(float, 32, 8, 0.012, 2);
        voltage_signals_[i * kSignalsPerMessage + 5] = new MakeUnsignedCANSignal(float, 40, 8, 0.012, 2);
        voltage_signals_[i * kSignalsPerMessage + 6] = new MakeUnsignedCANSignal(float, 48, 8, 0.012, 2);

        message_ptr_array[i] = new CANTXMessage<7>{bus,
                                                   512 + i,
                                                   7,
                                                   transmit_period,
                                                   *(voltage_signals_[i * kSignalsPerMessage + 0]),
                                                   *(voltage_signals_[i * kSignalsPerMessage + 1]),
                                                   *(voltage_signals_[i * kSignalsPerMessage + 2]),
                                                   *(voltage_signals_[i * kSignalsPerMessage + 3]),
                                                   *(voltage_signals_[i * kSignalsPerMessage + 4]),
                                                   *(voltage_signals_[i * kSignalsPerMessage + 5]),
                                                   *(voltage_signals_[i * kSignalsPerMessage + 6])};
    }
}

void BMSTelemetry::AttachTemperatureMessages(ICAN &bus,
                                             std::array<CANTXMessage<7> *, kNumTemperatureMessages> message_ptr_array,
                                             uint32_t transmit_period)
{
    for (uint16_t i = 0; i < kNumTemperatureMessages; i++)
    {
        temperature_signals_[i * kSignalsPerMessage + 0] = new MakeUnsignedCANSignal(float, 0, 8, 1, -40);
        temperature_signals_[i * kSignalsPerMessage + 1] = new MakeUnsignedCANSignal(float, 8, 8, 1, -40);
        temperature_signals_[i * kSignalsPerMessage + 2] = new MakeUnsignedCANSignal(float, 16, 8, 1, -40);
        temperature_signals_[i * kSignalsPerMessage + 3] = new MakeUnsignedCANSignal(float, 24, 8, 1, -40);
        temperature_signals_[i * kSignalsPerMessage + 4] = new MakeUnsignedCANSignal(float, 32, 8, 1, -40);
        temperature_signals_[i * kSignalsPerMessage + 5] = new MakeUnsignedCANSignal(float, 40, 8, 1, -40);
        temperature_signals_[i * kSignalsPerMessage + 6] = new MakeUnsignedCANSignal(float, 48, 8, 1, -40);

        message_ptr_array[i] = new CANTXMessage<7>{bus,
                                                   544 + i,
                                                   7,
                                                   transmit_period,
                                                   *(temperature_signals_[i * kSignalsPerMessage + 0]),
                                                   *(temperature_signals_[i * kSignalsPerMessage + 1]),
                                                   *(temperature_signals_[i * kSignalsPerMessage + 2]),
                                                   *(temperature_signals_[i * kSignalsPerMessage + 3]),
                                                   *(temperature_signals_[i * kSignalsPerMessage + 4]),
                                                   *(temperature_signals_[i * kSignalsPerMessage + 5]),
                                                   *(temperature_signals_[i * kSignalsPerMessage + 6])};
    }
}

void BMSTelemetry::UpdateSOESignals()
{
    max_discharge_signal_ = bms_.GetMaxDischargeCurrent();
    max_regen_signal_ = bms_.GetMaxRegenCurrent();
    battery_voltage_signal_ = bms_.GetPackVoltage();
    battery_temperature_signal_ = bms_.GetAverageCellTemperature();
    battery_current_signal_ = bms_.GetCurrent()[0];
};

void BMSTelemetry::UpdateFaultSignals()
{
    // *fault_summary_signal_ = (current_state_ == BMS::BMSState::kFault);
    undervoltage_signal_ = bms_.GetUnderVoltageFault();
    overvoltage_signal_ = bms_.GetOverVoltageFault();
    undertemperature_signal_ = bms_.GetUnderTemperatureFault();
    overtemperature_signal_ = bms_.GetOverTemperatureFault();
    overcurrent_signal_ = bms_.GetOverCurrentFault();
    external_kill_signal_ = bms_.GetExternalKillFault();
};

void BMSTelemetry::UpdateStatusSignals()
{
    state_signal_ = bms_.GetState();
    max_cell_temperature_signal_ = bms_.GetMaxCellTemperature();
    min_cell_temperature_signal_ = bms_.GetMinCellTemperature();
    max_cell_voltage_signal_ = bms_.GetMaxCellVoltage();
    min_cell_voltage_signal_ = bms_.GetMinCellVoltage();
    // soc_signal_;
};

void BMSTelemetry::TickHPCAN()
{
    UpdateSOESignals();
    UpdateStatusSignals();

    hp_can_bus_.Tick();
}

void BMSTelemetry::TickVBCAN()
{
    for (int i = 0; i < kNumVoltageMessages * kSignalsPerMessage; i++)
    {
        *(voltage_signals_[i]) = bms_.GetVoltages()[i];
    }

    for (int i = 0; i < kNumTemperatureMessages * kSignalsPerMessage; i++)
    {
        *(temperature_signals_[i]) = bms_.GetTemperatures()[i];
    }

    UpdateSOESignals();
    UpdateFaultSignals();
    UpdateStatusSignals();

    vb_can_bus_.Tick();
}

void BMSTelemetry::TickLPCAN()
{
    UpdateFaultSignals();

    vb_can_bus_.Tick();
}
