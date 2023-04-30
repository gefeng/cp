#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int maximizeSum(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        
        int x = nums.back();
        int y = x + k - 1;
        
        return (x + y) * k / 2;
    }
};
