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
    long long maximumSum(std::vector<int>& nums) {
        int n = nums.size();
        int64_t ans = 0;
        
        std::map<int, int64_t> m;
        m[1] += nums[0];
        for(int i = 2; i <= n; i++) {
            int x = i;
            int prod = 1;
            for(int f = 2; f * f <= x; f++) {
                if(x % f == 0) {
                    int cnt = 0;
                    while(x % f == 0) {
                        x /= f;
                        cnt += 1;
                    }
                    if(cnt % 2 == 1) {
                        prod *= f;
                    }
                }
            }
            if(x > 1) {
                prod *= x;
            }
            
            m[prod] += nums[i - 1];
        }
        
        for(auto [k, v] : m) {
            ans = std::max(ans, v);
        }
        
        return ans;
    }
};
