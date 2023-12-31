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
    bool hasTrailingZeros(std::vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += nums[i] % 2 == 0 ? 1 : 0;
        }
        return cnt > 1;
    }
};
