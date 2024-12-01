#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <numeric>

constexpr int INF = 1e9;

class Solution {
public:
    int getLargestOutlier(std::vector<int>& nums) {
        int n = nums.size();
        int ans = -INF;
        
        std::sort(nums.begin(), nums.end());
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        std::map<int, int> m;
        for(int x : nums) {
            m[x] += 1;
        }
    
        for(int i = 0; i < n; i++) {
            int s = sum - nums[i];
            m[nums[i]] -= 1;
            if(s % 2 == 0) {
                int x = s / 2;
                if(m.find(x) != m.end() && m[x] > 0) {
                    ans = nums[i];
                }
            }
            m[nums[i]] += 1;
        }
        
        return ans;
    }
};
