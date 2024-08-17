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
    std::vector<int> resultsArray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            int j = i;
            while(i + 1 < n && nums[i + 1] - nums[i] == 1) {
                i += 1;
            }

            for(int p = j; p <= i; p++) {
                if(p + k - 1 <= i) {
                    ans.push_back(nums[p + k - 1]);
                } else {
                    if(p <= n - k) {
                        ans.push_back(-1);
                    }
                }
            }
        }
        
        return ans;
    }
};
