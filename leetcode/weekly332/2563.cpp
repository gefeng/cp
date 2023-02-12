#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        return count(nums, upper) - count(nums, lower - 1);
    }
    
    LL count(vector<int>& nums, int upper) {
        int n = nums.size();
        LL ans = 0LL;
        for(int i = 0; i < n; i++) {
            auto it = upper_bound(nums.begin(), nums.end(), upper - nums[i]);
            int cnt = it - nums.begin() - i - 1;
            ans += max(0, cnt);
        }

        return ans;
    }
};
