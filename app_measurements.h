#ifndef APP_MEASUREMNTS.H
#define APP_MEASURMENTS.H
#include <vector>

using namespace std;

//enum class
enum class MeasurementStatus{
    SUCCESS,
    FAIL
};
class Measurements{
private:
    vector<float> meas_cellVoltages_V;
    vector<float> meas_cellTemps_C;
    float meas_current_mA;

public:
    //constructor declaration
    Measurements(int numCells, int numTemps){}

    //functions to simulate the data reading
    MeasurementStatus readCellVoltages(void);
    MeasurementStatus readCellTemps(void);
    MeasurementStatus readCellCurrent(void);

    //setter functions
    void setCellVolatges(vector<float>& cellVoltages);
    void setCellTemps(vector<float>& cellTemps);
    void setCellCurrent(float& cellCurrent);
    
    //getter functions
    vector<float> getCellVoltages(void)const;
    vector<float> getCellTemps(void)const;
    float getCellCurrent(void)const;
    
    //utility functions
    MeasurementStatus readBatteryData();

};

#endif