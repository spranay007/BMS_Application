#include "app_measurements.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iostream>

using namespace std;

//constructor definition
Measurements::Measurements(int numCells, int numTemps):
meas_cellVoltages_V(numCells, 0.0),
meas_cellTemps_C(numTemps, 0.0),
meas_current_mA(0.0)
{
    cout << "Initializing with numCells: " << numCells << ", numTemps: " << numTemps << endl;
    srand(static_cast<unsigned int>(time(nullptr))); //initilising the random seed
}


//function to simulate reading voltages in Volts
MeasurementStatus Measurements::readCellVoltages(void){
    for(int i = 0 ; i< meas_cellVoltages_V.size(); i++){
        meas_cellVoltages_V[i] = 3.0f + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(1.2f)));
    }
    cout<<"cell voltages initialized"<<endl;
    return MeasurementStatus::SUCCESS;
}

//function to read temps in C
MeasurementStatus Measurements::readCellTemps(void){
    for(int i = 0 ; i < meas_cellTemps_C.size(); i++){
        meas_cellTemps_C[i] = 20.0f+static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(20.0f)));
    }
    cout<<"cell temps initialized"<<endl;
    return MeasurementStatus::SUCCESS;
}

//function to read current in mA
MeasurementStatus Measurements::readCellCurrent(void){
    meas_current_mA = static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(10000.0f)));
    cout<<"current initialized"<<endl;
    return MeasurementStatus::SUCCESS;
}

//function to read all data at once
MeasurementStatus Measurements::readBatteryData(void){
    if(readCellVoltages() != MeasurementStatus::SUCCESS){
        return MeasurementStatus::FAIL;
    }
    if(readCellTemps() != MeasurementStatus::SUCCESS){
        return MeasurementStatus::FAIL;
    }
    if(readCellCurrent() != MeasurementStatus::SUCCESS){
        return MeasurementStatus::FAIL;
    }
    return MeasurementStatus::SUCCESS;
}

//setter functions
void Measurements::setCellVolatges(vector<float>& cellVoltages){
    if(cellVoltages.size() != meas_cellVoltages_V.size()){
        throw invalid_argument("size mismatch for cell voltages");
    }
    meas_cellVoltages_V = cellVoltages;
}

void Measurements::setCellTemps(vector<float>& cellTemps){
    if(cellTemps.size() != meas_cellTemps_C.size()){
        throw invalid_argument("size mismatch for cell Temps");
    }
    meas_cellTemps_C = cellTemps;
}

void Measurements::setCellCurrent(float& cellCurrent){
    meas_current_mA = cellCurrent;
}

//getter functions
vector<float> Measurements::getCellVoltages(void)const{
    return meas_cellVoltages_V;
}

vector<float> Measurements::getCellTemps(void)const{
    return meas_cellTemps_C;
}

float Measurements::getCellCurrent(void)const{
    return meas_current_mA;
}