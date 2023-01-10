#pragma once

#include <SD.h>
#include <vector>

//create an sdlogger class 

class SdLogger
{
    // create functions so that bms doesn't get unnecessary information
    public:

    void fileOpen();

    void fileClose();

    void fileWrite(uint32_t current_time, std::vector<float> current, std::vector<float> voltages,std::vector<float> temperatures);

    void fileJump();

    void WriteLabels(int num_voltages, int num_temperatures);

    private:

    File data;

};