#include "test_usb_device.h"
#include "usb_device.h"
#include "usb_vendors.h"

namespace {
    class TestUsbDevice : public TestInfo, public UsbDevice {
    };

    TEST_F(TestUsbDevice, GetDeviceDescriptor) {
        EXPECT_EQ(GetDeviceDescriptor().idVendor, UsbVendor::None);
        EXPECT_EQ(GetDeviceDescriptor().bcdUSB, 0x0110);
    }

    TEST_F(TestUsbDevice, GetUsbSpecVer) {
        EXPECT_EQ(GetUsbSpecVer(), UsbSpecVer::USB1_1);
    }

} // namespace