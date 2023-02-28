#include "bms_telemetry.h"

void BMSTelemetry::InitializeCAN()
{
  hp_can_bus_.Initialize(ICAN::BaudRate::kBaud1M);
  vb_can_bus_.Initialize(ICAN::BaudRate::kBaud1M);
  lp_can_bus_.Initialize(ICAN::BaudRate::kBaud1M);

  InitializeHPMessages();
  InitializeLPMessages();
  InitializeVBMessages();

  timer_group_.AddTimer(kHPTransmitPeriod, [this]() { this->TickHPCAN(); });
  timer_group_.AddTimer(kVBTransmitPeriod, [this]() { this->TickVBCAN(); });
  timer_group_.AddTimer(kLPTransmitPeriod, [this]() { this->TickLPCAN(); });
}

void BMSTelemetry::InitializeHPMessages()
{
  AttachSOEMessage(hp_can_bus_, hp_soe_message_, kHPTransmitPeriod);
  AttachStatusMessage(hp_can_bus_, hp_status_message_, kHPTransmitPeriod);
}

void BMSTelemetry::InitializeVBMessages()
{
  AttachVoltageMessages(vb_can_bus_, voltage_messages_, kVBTransmitPeriod);
  AttachTemperatureMessages(vb_can_bus_, temperature_messages_, kVBTransmitPeriod);
  AttachSOEMessage(vb_can_bus_, vb_soe_message_, kVBTransmitPeriod);
  AttachFaultMessage(vb_can_bus_, vb_fault_message_, kVBTransmitPeriod);
  AttachStatusMessage(vb_can_bus_, vb_status_message_, kVBTransmitPeriod);
}

void BMSTelemetry::InitializeLPMessages()
{
  AttachFaultMessage(lp_can_bus_, lp_fault_message_, kLPTransmitPeriod);
}

void BMSTelemetry::AttachVoltageMessages(
  ICAN &bus,
  std::array<CANTXMessage<7>*, kNumVoltageMessages> message_ptr_array,
  uint32_t transmit_period
) {
  for (int i = 0; i < kNumVoltageMessages; i++) {
    voltage_signals_[i * kSignalsPerMessage + 0] = new MakeUnsignedCANSignal(float,  0, 8, 0.012, 2);
    voltage_signals_[i * kSignalsPerMessage + 1] = new MakeUnsignedCANSignal(float,  8, 8, 0.012, 2);
    voltage_signals_[i * kSignalsPerMessage + 2] = new MakeUnsignedCANSignal(float, 16, 8, 0.012, 2);
    voltage_signals_[i * kSignalsPerMessage + 3] = new MakeUnsignedCANSignal(float, 24, 8, 0.012, 2);
    voltage_signals_[i * kSignalsPerMessage + 4] = new MakeUnsignedCANSignal(float, 32, 8, 0.012, 2);
    voltage_signals_[i * kSignalsPerMessage + 5] = new MakeUnsignedCANSignal(float, 40, 8, 0.012, 2);
    voltage_signals_[i * kSignalsPerMessage + 6] = new MakeUnsignedCANSignal(float, 48, 8, 0.012, 2);

    message_ptr_array[i] = new CANTXMessage<7>{bus, 512 + i, 7, transmit_period,
      *(voltage_signals_[i * kSignalsPerMessage + 0]),
      *(voltage_signals_[i * kSignalsPerMessage + 1]),
      *(voltage_signals_[i * kSignalsPerMessage + 2]),
      *(voltage_signals_[i * kSignalsPerMessage + 3]),
      *(voltage_signals_[i * kSignalsPerMessage + 4]),
      *(voltage_signals_[i * kSignalsPerMessage + 5]),
      *(voltage_signals_[i * kSignalsPerMessage + 6])};
  }
}

void BMSTelemetry::AttachTemperatureMessages(
  ICAN &bus,
  std::array<CANTXMessage<7>*, kNumTemperatureMessages> message_ptr_array,
  uint32_t transmit_period
) {
  for (int i = 0; i < kNumTemperatureMessages; i++) {
    temperature_signals_[i * kSignalsPerMessage + 0] = new MakeUnsignedCANSignal(float,  0, 8, 1, -40);
    temperature_signals_[i * kSignalsPerMessage + 1] = new MakeUnsignedCANSignal(float,  8, 8, 1, -40);
    temperature_signals_[i * kSignalsPerMessage + 2] = new MakeUnsignedCANSignal(float, 16, 8, 1, -40);
    temperature_signals_[i * kSignalsPerMessage + 3] = new MakeUnsignedCANSignal(float, 24, 8, 1, -40);
    temperature_signals_[i * kSignalsPerMessage + 4] = new MakeUnsignedCANSignal(float, 32, 8, 1, -40);
    temperature_signals_[i * kSignalsPerMessage + 5] = new MakeUnsignedCANSignal(float, 40, 8, 1, -40);
    temperature_signals_[i * kSignalsPerMessage + 6] = new MakeUnsignedCANSignal(float, 48, 8, 1, -40);

    message_ptr_array[i] = new CANTXMessage<7>{bus, 544 + i, 7, transmit_period,
      *(temperature_signals_[i * kSignalsPerMessage + 0]),
      *(temperature_signals_[i * kSignalsPerMessage + 1]),
      *(temperature_signals_[i * kSignalsPerMessage + 2]),
      *(temperature_signals_[i * kSignalsPerMessage + 3]),
      *(temperature_signals_[i * kSignalsPerMessage + 4]),
      *(temperature_signals_[i * kSignalsPerMessage + 5]),
      *(temperature_signals_[i * kSignalsPerMessage + 6])};
  }
}

void BMSTelemetry::AttachSOEMessage(
  ICAN &bus,
  CANTXMessage<5>* message_ptr,
  uint32_t transmit_period
) {
  max_discharge_signal_ = new MakeUnsignedCANSignal(float, 0, 12, 0.1, 0);
  max_regen_signal_ = new MakeUnsignedCANSignal(float, 12, 12, 0.1, 0);
  battery_voltage_signal_ = new MakeUnsignedCANSignal(float, 24, 16, 0.01, 0);
  battery_temperature_signal_ = new MakeUnsignedCANSignal(float, 40, 8, 1, -40);
  battery_current_signal_ = new MakeSignedCANSignal(float, 48, 16, 0.01, 0);

  message_ptr = new CANTXMessage<5>{bus, 576, 5, transmit_period,
    *max_discharge_signal_,
    *max_regen_signal_,
    *battery_voltage_signal_,
    *battery_temperature_signal_,
    *battery_current_signal_};
}

void BMSTelemetry::AttachFaultMessage(
  ICAN &bus,
  CANTXMessage<7>* message_ptr,
  uint32_t transmit_period
) {
  summary_signal_ = new MakeUnsignedCANSignal(bool, 0, 1, 1, 0);
  undervoltage_signal_ = new MakeUnsignedCANSignal(bool, 2, 1, 1, 0);
  overvoltage_signal_ = new MakeUnsignedCANSignal(bool, 3, 1, 1, 0);
  undertemperature_signal_ = new MakeUnsignedCANSignal(bool, 3, 1, 1, 0);
  overtemperature_signal_ = new MakeUnsignedCANSignal(bool, 4, 1, 1, 0);
  overcurrent_signal_ = new MakeUnsignedCANSignal(bool, 5, 1, 1, 0);
  external_kill_signal_ = new MakeUnsignedCANSignal(bool, 6, 1, 1, 0);

  message_ptr = new CANTXMessage<7>{bus, 592, 7, transmit_period,
    *summary_signal_,
    *undervoltage_signal_,
    *overvoltage_signal_,
    *undertemperature_signal_,
    *overtemperature_signal_,
    *overcurrent_signal_,
    *external_kill_signal_};
}

void BMSTelemetry::AttachStatusMessage(
  ICAN &bus,
  CANTXMessage<6>* message_ptr,
  uint32_t transmit_period
) {
  state_signal_ = new MakeUnsignedCANSignal(uint8_t, 48, 8, 1, 0);
  max_cell_temperature_signal_ = new MakeUnsignedCANSignal(float, 8, 8, 1, -40);
  min_cell_temperature_signal_ = new MakeUnsignedCANSignal(float, 16, 8, 1, -40);
  max_cell_voltage_signal_ = new MakeUnsignedCANSignal(float, 24, 8, 0.012, 2);
  min_cell_voltage_signal_ = new MakeUnsignedCANSignal(float, 32, 8, 0.012, 2);
  soc_signal_ = new MakeUnsignedCANSignal(float, 40, 8, 0.5, 0);

  message_ptr = new CANTXMessage<6>{bus, 577, 6, transmit_period,
    *state_signal_,
    *max_cell_temperature_signal_,
    *min_cell_temperature_signal_,
    *max_cell_voltage_signal_,
    *min_cell_voltage_signal_,
    *soc_signal_};
}

void BMSTelemetry::UpdateSOESignals()
{
  *max_discharge_signal_ = max_discharge_current_value_;
  *max_regen_signal_ = max_regen_current_value_;
  *battery_voltage_signal_ = battery_voltage_value_;
  *battery_temperature_signal_ = temperature_values_[0]; // ??
  *battery_current_signal_ = current_value_[0];
};

void BMSTelemetry::UpdateFaultSignals()
{
  // *summary_signal_ = (current_state_ == BMS::BMSState::kFault);
  *undervoltage_signal_ = undervoltage_fault_value_;
  *overvoltage_signal_ = overvoltage_fault_value_;
  *undertemperature_signal_ = undertemperature_fault_value_;
  *overtemperature_signal_ = overtemperature_fault_value_;
  *overcurrent_signal_ = overcurrent_fault_value_;
  *external_kill_signal_ = external_kill_fault_value_;
};

void BMSTelemetry::UpdateStatusSignals()
{
  // state_signal_ = current_state_;
  *max_cell_temperature_signal_ = max_cell_temperature_value_;
  *min_cell_temperature_signal_ = min_cell_temperature_value_;
  *max_cell_voltage_signal_ = max_cell_voltage_value_;
  *min_cell_voltage_signal_ = min_cell_voltage_value_;
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
  for (int i = 0; i < kNumVoltageMessages * kSignalsPerMessage; i++) {
    *(voltage_signals_[i]) = voltage_values_[i];
  }

  for (int i = 0; i < kNumTemperatureMessages * kSignalsPerMessage; i++) {
    *(temperature_signals_[i]) = temperature_values_[i];
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
