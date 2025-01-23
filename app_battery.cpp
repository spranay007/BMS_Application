#include "app_battery.h"
#include <stdexcept>

//constructor definataion
Battery::Battery(int numcells, int numTempSensors, BatteryType type):
batteryMeasurements(numcells, numTempSensors),
batteryType(type){}

//setter functions

void Battery::setBatteryType(BatteryType type){
    if(!(checkBatteryTypeValidity(type))){
        throw invalid_argument("battery type cant be negative");
    }
    batteryType = type;
}

//getter functions
const vector<float> Battery::getCellVoltages(void)const{
    return batteryMeasurements.getCellVoltages();
}

const vector<float> Battery::getCellTemps(void)const{
    return batteryMeasurements.getCellTemps();
}

float Battery::getCurrent(void)const{
    return batteryMeasurements.getCellCurrent();
}

BatteryType Battery::getBatteryType(void)const{
    return batteryType;
}

//utility functions

bool Battery::checkBatteryTypeValidity(BatteryType type){
    return type == BatteryType::LITHIUM_ION ||
    type == BatteryType::NICKEL_METAL_HYDRIDE||
    type == BatteryType::LEAD_ACID||
    type == BatteryType::LITHIUM_POLYMER;
}

void Battery::readBatteryData(void){
    batteryMeasurements.readBatteryData();
}