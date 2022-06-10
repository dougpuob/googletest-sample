#include <vector>
#pragma once

class BinarySearch {
 public:
   virtual int search() = 0;
   virtual int search(std::vector<int> &nums, int target) = 0;
};