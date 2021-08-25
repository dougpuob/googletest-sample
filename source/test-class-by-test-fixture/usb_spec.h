#pragma once

#include <cinttypes>

enum class UsbDeviceSpeed {
    UsbLowSpeed = 0,
    UsbFullSpeed,
    UsbHighSpeed,
    UsbSuperSpeed
};

enum class UsbSpecVer {
    USB1_1 = 0x0110, // USB 1.1
    USB2_0 = 0x0200, // USB 2.0
    USB2_1 = 0x0210, // USB 2.1
    USB2_5 = 0x0250, // USB 2.5
    USB3_0 = 0x0300, // USB 3.0
    USB3_1 = 0x0310, // USB 3.1
    USB3_2 = 0x0320  // USB 3.2
};


struct USB_DEVICE_DESCRIPTOR {
    std::uint8_t    bLength;
    std::uint8_t    bDescriptorType;
    std::uint16_t   bcdUSB;
    std::uint8_t    bDeviceClass;
    std::uint8_t    bDeviceSubClass;
    std::uint8_t    bDeviceProtocol;
    std::uint8_t    bMaxPacketSize0;
    std::uint16_t   idVendor;
    std::uint16_t   idProduct;
    std::uint16_t   bcdDevice;
    std::uint8_t    iManufacturer;
    std::uint8_t    iProduct;
    std::uint8_t    iSerialNumber;
    std::uint8_t    bNumConfigurations;
};