#ifndef APP_BATTERY_H
#define APP_BATTERY_H

#include <vector>
#include "app_measurements.h"

using namespace std;

enum class BatteryType{
    LITHIUM_ION = 0,
    NICKEL_METAL_HYDRIDE = 1,
    LEAD_ACID = 2,
    LITHIUM_POLYMER = 3
};

class Battery{
    private:
        Measurements batteryMeasurements;
        BatteryType batteryType;
    public:
        Battery(int numcells, int numTempSensors, BatteryType type); 

        //setter functions
        // void setCellVoltages(const vector<float>& cellVolatges);
        // void setCellTemps(const vector<float>& cellTemps);
        // void setCurrent(float current);
        void setBatteryType(BatteryType type);

        //getter functions
        const vector<float> getCellVoltages(void) const;
        const vector<float> getCellTemps(void) const;
        float getCurrent(void) const;
        BatteryType getBatteryType(void) const;

        //utility functions
        // size_t getCellCount(void) const;
        // size_t getCellTempCount(void) const;
        bool checkBatteryTypeValidity(BatteryType type);
        void readBatteryData();
};

#endif