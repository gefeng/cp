#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

class Solution {
public:
    int sumDistance(std::vector<int>& nums, std::string s, int d) {
        int n = nums.size();
        std::vector<LL> pos(n);
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'R') {
                pos[i] = 1LL * nums[i] + d;
            } else {
                pos[i] = 1LL * nums[i] - d;
            }
        }
        
        std::sort(pos.begin(), pos.end());
        
        LL ans = 0LL;
        LL sum = 0LL;
        
        for(int i = 1; i < n; i++) {
            sum += (pos[i] - pos[i - 1]) * i % MOD;
            sum %= MOD;
            ans += sum;
            ans %= MOD;
        }
        
        return ans;
    }
};
