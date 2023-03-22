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
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> seen(1001, 0);
        return dfs(nums, k, seen, 0) - 1;
    }
    
    int dfs(vector<int>& nums, int k, vector<int>& seen, int i) {
        if(i == nums.size()) {
            return 1;
        }
        
        int res = dfs(nums, k, seen, i + 1);
        
        int v = nums[i];
        if((v - k < 0 || !seen[v - k]) && (v + k > 1000 || !seen[v + k])) {
            seen[v] += 1;
            res += dfs(nums, k, seen, i + 1);
            seen[v] -= 1;
        }
        
        return res;
    }
};
