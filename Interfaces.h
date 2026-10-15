#ifndef INTERFACES_H
#define INTERFACES_H

#include <string>


class Powerable {
public:
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual std::string getPowerStatus() = 0;
    virtual ~Powerable() = default;
};


class Connectable {
public:
    virtual void connect(const std::string& network) = 0;
    virtual void disconnect() = 0;
    virtual std::string getConnectionInfo() = 0;
    virtual ~Connectable() = default;
};

#endif
