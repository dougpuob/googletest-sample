#include "usb_device.h"
#include "gtest/gtest.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int Ret = RUN_ALL_TESTS();
  return Ret;
}
