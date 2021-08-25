#pragma once

#include "usb_device.h"

class LogitechK840 : public UsbDevice{
public:    
    LogitechK840();
    virtual ~LogitechK840() {};
    const USB_DEVICE_DESCRIPTOR& GetDeviceDescriptor();
};