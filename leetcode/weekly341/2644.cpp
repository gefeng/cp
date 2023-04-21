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
    int maxDivScore(std::vector<int>& nums, std::vector<int>& divisors) {
        int ans = (int)1e9;
        int max_f = 0;
        
        for(int d : divisors) {
            int cnt = 0;
            for(int x : nums) {
                if(x % d == 0) {
                    cnt += 1;
                }
            }
            if(cnt > max_f) {
                max_f = cnt;
                ans = d;
            } else if(cnt == max_f) {
                ans = std::min(ans, d);
            }
        }
        
        return ans;
    }
};
