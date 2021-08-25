#include "usb_vendors.h"
#include "test_usb_device.h"
#include "usb_device_logitech_k840.h"

namespace {
    class TestLogitechK840 : public TestInfo, public LogitechK840 {
    };

    TEST_F(TestLogitechK840, GetDeviceDescriptor) {
        EXPECT_EQ(GetDeviceDescriptor().idVendor, UsbVendor::Logitech);
        EXPECT_EQ(GetDeviceDescriptor().bcdUSB, 0x200);
    }

    TEST_F(TestLogitechK840, GetUsbSpecVer) {
        EXPECT_EQ(GetUsbSpecVer(), UsbSpecVer::USB2_0);
    }

} // namespace