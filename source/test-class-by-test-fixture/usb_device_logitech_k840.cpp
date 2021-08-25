#include "usb_device_logitech_k840.h"

LogitechK840::LogitechK840() {
    this->UsbDeviceDescriptor_ = {
        .bLength            = 0x12,     // bLength:             0x12
        .bDescriptorType    = 0x01,     // bDescriptorType:     0x01
        .bcdUSB             = 0x0200,   // bcdUSB:              0x0200
        .bDeviceClass       = 0x00,     // bDeviceClass:        0x00
        .bDeviceSubClass    = 0x00,     // bDeviceSubClass:     0x00
        .bDeviceProtocol    = 0x00,     // bDeviceProtocol:     0x00
        .bMaxPacketSize0    = 0x40,     // bMaxPacketSize0:     0x40
        .idVendor           = 0x046D,   // idVendor:            0x046D (Logitech Inc.)
        .idProduct          = 0xC33B,   // idProduct:           0xC33B
        .bcdDevice          = 0x1500,   // bcdDevice:           0x1500
        .iManufacturer      = 0x01,     // iManufacturer:       0x01    English (United States)  "Logitech"
        .iProduct           = 0x02,     // iProduct:            0x02    English (United States)  "K840 Mechanical Corded Keyboard"
        .iSerialNumber      = 0x03,     // iSerialNumber:       0x03    English (United States)  "028D376B3235"
        .bNumConfigurations = 0x01      // bNumConfigurations:  0x01
    };
    }
const USB_DEVICE_DESCRIPTOR& LogitechK840::GetDeviceDescriptor() {
    return this->UsbDeviceDescriptor_;
}