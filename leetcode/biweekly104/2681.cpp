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
    int sumOfPower(std::vector<int>& nums) {
        int n = nums.size();
        LL ans = 0LL;
        LL sum = 0LL;
        
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            LL x = (1LL * nums[i] * nums[i]) % MOD;
            ans += x * nums[i] % MOD;
            ans %= MOD;
            
            ans += sum * x % MOD;
            ans %= MOD;
            
            sum *= 2LL;
            sum %= MOD;
            sum += nums[i];
            sum %= MOD;
        }
        
        return ans;
    } 
};
