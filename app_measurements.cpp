#include "app_measurements.h"
//prototypes

//class definitions
class measurements{
public:
    int app_readCurrent();
    int app_readVoltage();
    int app_readTemps();
private:
    float meas_current;

};
//definations
