/*
 * Author: Mukhammadkhon Asrorov 
 * Date: 14/01/2024
 * Name: hw-10
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hasZeroSumTriplet(const vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;
        int target = -nums[i]; 

        while (left < right) {
            int currentSum = nums[left] + nums[right];

            if (currentSum == target) {
                return true;
            } else if (currentSum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }

    return false;
}

int main() {
    vector<int> nums = {-5, -17, 7, -4, 3, -2, 4};

    bool result = hasZeroSumTriplet(nums);

    cout << (result ? "True" : "False") << endl;

    return 0;
}
