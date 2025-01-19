#include "app_battery.h"
#include "stdexcept"

//constructor definataion
battery::battery(int numcells, int numTempSensors, BatteryType type):
meas_cellVoltages(numcells, 0.0),
meas_cellTemps(numTempSensors, 0.0),
meas_current(0.0),
batteryType(type){}

//setter functions
void battery::setCellVoltages(const vector<float>& cellVoltages){
    if(cellVoltages.size() != meas_cellVoltages.size()){
        throw invalid_argument("size mismatch for cell voltages");
    }
    meas_cellVoltages = cellVoltages;
}

void battery::setCellTemps(const vector<float>& cellTemps){
    if(cellTemps.size() != meas_cellTemps.size()){
        throw invalid_argument("size mismatch for cell temps");
    }
    meas_cellTemps = cellTemps;
}

void battery::setCurrent(float current){
    meas_current = current;
}

void battery::setBatteryType(BatteryType type){
    if(!(checkBatteryTypeValidity(type))){
        throw invalid_argument("battery type cant be negative");
    }
    batteryType = type;
}

//getter functions
vector<float> battery::getCellVoltages(void)const{
    return meas_cellVoltages;
}

vector<float> battery::getCellTemps(void)const{
    return meas_cellTemps;
}

float battery::getCurrent(void)const{
    return meas_current;
}

BatteryType battery::getBatteryType(void)const{
    return batteryType;
}

//utility functions
size_t battery::getCellCount(void)const{
    return meas_cellVoltages.size();

}
size_t battery::getCellTempCount(void)const{
    return meas_cellTemps.size();
}

bool battery::checkBatteryTypeValidity(BatteryType type){
    return type == BatteryType::LITHIUM_ION ||
    type == BatteryType::NICKEL_METAL_HYDRIDE||
    type == BatteryType::LEAD_ACID||
    type == BatteryType::LITHIUM_POLYMER;
}