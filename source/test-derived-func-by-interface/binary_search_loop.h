#pragma once

#include "binary_search.h"

class BinarySearchLoop : BinarySearch {
 public:
  int search(std::vector<int>& nums, int target) {
    // std::ios_base::sync_with_stdio(false);

    int mid = 0;
    int left = 0;
    int right = nums.size() - 1;

    while (true) {
      mid = left + ((right - left) / 2);
      if (nums[left] > target || nums[right] < target)
        return -1;
      else if (nums[mid] == target)
        return mid;
      else if (target > nums[mid])
        left = mid + 1;
      else if (target < nums[mid])
        right = mid - 1;
      else
        return -1;
    }
    return -1;
  }
};