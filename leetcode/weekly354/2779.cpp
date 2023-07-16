#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = (int)2e5 + 10;

class Solution {
public:
    int maximumBeauty(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        std::vector<int> diff(MAX, 0);
        for(int i = 0; i < n; i++) {
            int l = std::max(0, nums[i] - k);
            int r = nums[i] + k;
            diff[l] += 1;
            diff[r + 1] -= 1;
        }
        
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < MAX; i++) {
            cnt += diff[i];
            ans = std::max(ans, cnt);
        }
        
        return ans;
    }
};
