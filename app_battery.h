#ifdef APP_BATTERY.H
#define APP_BATTERY.H

using namespace std;

enum class BatteryType{
    LITHIUM_ION = 0,
    NICKEL_METAL_HYDRIDE = 1,
    LEAD_ACID = 2,
    LITHIUM_POLYMER = 3
};

class battery{
    private:
        vector<float> meas_cellVoltages;
        vector<float> meas_cellTemps;
        float meas_current;
        BatteryType batteryType;
    public:
        battery(int numcells, int numTempSensors, BatteryType type)
        : meas_cellVoltages(numcells, 0.0),
        meas_cellTems(numTempSensors, 0.0),
        meas_current(0.0);
        batteryType(type){}
        
        void setBatteryType(BatteryType type){batteryType = type;};
        BatteryType getBatteryType()const{return batteryType;};
}

#endif