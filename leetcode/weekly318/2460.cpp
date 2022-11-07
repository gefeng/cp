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
     vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        vector<int> ans(n, 0);
        for(int i = 0, j = 0; i < n; i++) {
            if(nums[i] != 0) {
                ans[j++] = nums[i];
            }
        }
        
        return ans;
    }
};
