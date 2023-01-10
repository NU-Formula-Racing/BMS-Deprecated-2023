#include <SD.h>
#include <Arduino.h>
#include <sdlogger.h>
#include <SPI.h>




// ver se está aberto, se não, crie file

void SdLogger::fileOpen()

{
  data = SD.open("data.csv", FILE_WRITE);
}

void SdLogger::fileWrite(uint32_t current_time, std::vector<float> current, std::vector<float> voltages, std::vector<float> temperatures)
{
  data.print(current_time);
  data.print(",");
  data.print(current[0]);

  for (int i = 0; i < voltages.size(); i++)
  {
    data.print(",");
    data.print(voltages[i]);
  }

  for (int i = 0; i < temperatures.size(); i++)
  {
    data.print(",");
    data.print(temperatures[i]);
  }

  data.print("\n");
}
// naming file columns

void SdLogger::WriteLabels(int num_voltages, int num_temperatures)
{
  data.print("time");
  data.print(",");
  data.print("current");

  for (int i = 0; i < num_voltages; i++)
  {
    data.print(",");
    data.print("voltage_");
    data.print(i);
  }

  for (int i = 0; i < num_temperatures; i++)
  {
    data.print(",");
    data.print("temperature_");
    data.print(i);
  }
  data.print("\n");
}

void SdLogger::fileJump()
{
  data.print(",");
}

// fechar file

void SdLogger::fileClose()
{
  // close file when shutdownCar() has been called
  // delete file
  data.close();
}