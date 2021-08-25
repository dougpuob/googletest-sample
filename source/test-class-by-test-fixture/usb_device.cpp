#include "usb_device.h"

UsbDevice::UsbDevice() {
    this->UsbDeviceDescriptor_ = {
        .bLength            = 0x12,
        .bDescriptorType    = 0x00,
        .bcdUSB             = 0x0110,
        .bDeviceClass       = 0x00,
        .bDeviceSubClass    = 0x00,
        .bDeviceProtocol    = 0x00,
        .bMaxPacketSize0    = 0x00,
        .idVendor           = 0x0000,
        .idProduct          = 0x0000,
        .bcdDevice          = 0x0000,
        .iManufacturer      = 0x00,  
        .iProduct           = 0x00,  
        .iSerialNumber      = 0x00,  
        .bNumConfigurations = 0x00   
    };
}

const USB_DEVICE_DESCRIPTOR& UsbDevice::GetDeviceDescriptor() {
    return this->UsbDeviceDescriptor_;
}

UsbSpecVer UsbDevice::GetUsbSpecVer() {
    return static_cast<UsbSpecVer>(this->UsbDeviceDescriptor_.bcdUSB);
}
