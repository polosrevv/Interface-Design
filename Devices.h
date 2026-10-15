#ifndef DEVICES_H
#define DEVICES_H

#include "Interfaces.h"
#include <iostream>
#include <string>


class Lamp : public Powerable {
private:
    bool isOn = false;
    std::string name;
public:
    Lamp(std::string name) : name(name){

    }
    void powerOn() override {
        this->isOn = true;
        std::cout << this->name << ": Light turned on";
    }

    void powerOff() override {
        this->isOn = false;
        std::cout << this->name << ": Light turned off";
    }
    std::string getPowerStatus() override {
        if(isOn){
            return "ON";
        }
        else{
            return "OFF";
        }
    }
};

class SmartTV : public Powerable, public Connectable {
private:
    bool isOn = false;
    std::string brand;
    std::string currentNetwork = "";
public:
    SmartTV(std::string brand) : brand(brand){
        
    }
    void powerOn() override {
        this->isOn = true;
        std::cout << this->brand << " TV: Powered on";
    }

    void powerOff() override {
        this->isOn = false;
        currentNetwork = "";
        std::cout << this->brand << " TV: Powered off";
    }

    std::string getPowerStatus() override {
        if(this->isOn == true){
            return "ON";
        }
        else{
            return "OFF";
        }
    }
    void connect(const std::string& network) override {
        this->currentNetwork = network;
        std::cout << this->brand << " TV: Connected to " << this->currentNetwork;
    }

    void disconnect() override {
        std::cout << this->brand << " TV: Disconnected";
    }

    std::string getConnectionInfo() override {
        if(this->currentNetwork != ""){
            return "Connected to " + this->currentNetwork;
        }
            return "Not connected";
    }
};

#endif
