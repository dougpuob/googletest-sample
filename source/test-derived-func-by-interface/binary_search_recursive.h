#pragma once

#include "binary_search.h"

class BinarySearchRecursive : BinarySearch {
 public:
  int search(std::vector<int>& nums, int target) {
    // std::ios_base::sync_with_stdio(false);
    return this->search_by_recursive(nums, 0, nums.size(), target);
  }

  int search_by_recursive(std::vector<int>& nums,
                          int left,
                          int right,
                          int target) {
    int mid = left + ((right - left) / 2);
    if (nums[mid] == target)
      return mid;
    else if (right - 1 == left)
      return -1;
    else if (nums[mid] > target)
      return search_by_recursive(nums, 0, mid, target);
    else if (nums[mid] < target)
      return search_by_recursive(nums, mid, right, target);
    else
      return -1;
  }
};