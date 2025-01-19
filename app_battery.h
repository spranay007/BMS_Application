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
        battery(int numcells, int numTempSensors, BatteryType type); 
        
        //setter functions
        void setCellVoltages(const vector<float>& cellVolatges);
        void setCellTemps(const vector<float>& cellTemps);
        void setCurrent(float current);
        void setBatteryType(BatteryType type);
        //getter functions
        vector<float> getCellVoltages(void) const;
        vector<float> getCellTemps(void) const;
        float getCurrent(void) const;
        BatteryType getBatteryType(void) const;

        //utility functions
        size_t getCellCount(void) const;
        size_t getCellTempCount(void) const;
}

#endif