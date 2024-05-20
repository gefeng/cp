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
    long long sumDigitDifferences(std::vector<int>& nums) {
        int64_t ans = 0;
        int n = nums.size();
        
        while(true) {
            if(nums[0] == 0) {
                break;
            }
            
            std::array<int, 10> cnt{};
            for(int i = 0; i < n; i++) {
                cnt[nums[i] % 10] += 1;
                nums[i] /= 10;
            }
            
            for(int i = 0; i < 10; i++) {
                ans += (int64_t)(n - cnt[i]) * cnt[i];
            }
        }
        
        return ans / 2;
    }
};
