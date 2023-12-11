#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

class Solution {
public:
    int numberOfGoodPartitions(std::vector<int>& nums) {
        int n = nums.size();
        std::map<int, int> m;
        
        for(int i = 0; i < n; i++) {
            m[nums[i]] = i;    
        }
        
        int cnt = 0;
        for(int i = 0, j = 0; i < n; i++) {
            int last = m[nums[i]];
            if(last < j) {
                continue;
            }
            if(last > j) {
                j = last;
            }
            
            if(i == j) {
                cnt += 1;
            }
        }
        
        int64_t ans = 1;
        for(int i = 0; i < cnt - 1; i++) {
            ans *= 2;
            ans %= MOD;
        }
        return ans;
    }
};
