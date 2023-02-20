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

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        if(n == 3) {
            return 0;
        }
        
        int ans = min(nums[n - 1] - nums[2], nums[n - 3] - nums[0]);
        ans = min(ans, nums[n - 2] - nums[1]);
        
        return ans;
    }
};
