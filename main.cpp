#include <iostream>
#include <string>
#include "Devices.h"

using namespace std;

int main() {
    // Read inputs
    string lampName;
    string tvBrand;
    string networkName;
    
    getline(cin, lampName);
    getline(cin, tvBrand);
    getline(cin, networkName);
    Powerable* arr[2];
    arr[0] = new Lamp(lampName);
    arr[1] = new SmartTV(tvBrand);
    for(int i{};i<2;i++){
        arr[i]->powerOn();
        std::cout << "\n";
        std::cout << "Status: " << arr[i]->getPowerStatus() << "\n";
    }
    std::cout << "\n";
    Connectable* tvConnect = dynamic_cast<Connectable*>(arr[1]);
    tvConnect->connect(networkName);
    std::cout << "\n";
    std::cout << "Connection: " << tvConnect->getConnectionInfo() << "\n";

    std::cout << "\n";
    
    for(int i {0}; i < 2; i++) {
        arr[i]->powerOff();
        std::cout << "\n";
        std::cout << "Status: " << arr[i]->getPowerStatus();
        if (i == 0) {
            std::cout << "\n"; 
        }
    }
    return 0;
}
