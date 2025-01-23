#include <iostream>
#include <chrono>
#include "app_battery.h"
#include <thread>

using namespace std;

int main() {
    // Create a battery with 16 cells, 10 temperature sensors, and type Lithium-Ion
    Battery myBattery(16, 10, BatteryType::LITHIUM_ION);

    // Set the time limit (in seconds)
    int timeLimit = 10; // 10 seconds
    auto start = chrono::steady_clock::now();
    auto end = start + chrono::seconds(timeLimit);

    while (chrono::steady_clock::now() < end) {
        // Read the battery data in each loop
        myBattery.readBatteryData();

        // Access the measurement data
        const auto& voltages = myBattery.getCellVoltages();
        const auto& temps = myBattery.getCellTemps();
        float current = myBattery.getCurrent();

        // Print the data
        cout << "Cell Voltages: ";
        for (float voltage : voltages) {
            cout << voltage << " ";
        }
        cout << "\n";

        cout << "Cell Temperatures: ";
        for (float temp : temps) {
            cout << temp << " ";
        }
        cout << "\n";

        cout << "Current: " << current << " A\n";

        // Adding a small delay between cycles
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "Time limit reached, exiting program...\n";

    return 0;
}
