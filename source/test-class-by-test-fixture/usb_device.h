#pragma once

#include "usb_spec.h"

class UsbDevice {
protected:
    USB_DEVICE_DESCRIPTOR UsbDeviceDescriptor_;

public:    
    UsbDevice();
    virtual ~UsbDevice() {};
    virtual const USB_DEVICE_DESCRIPTOR& GetDeviceDescriptor();
    virtual UsbSpecVer GetUsbSpecVer();
};