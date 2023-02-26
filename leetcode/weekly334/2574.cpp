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
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            ans[i] += sum;
            sum += nums[i];
        }
        
        sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = abs(ans[i] - sum);
            sum += nums[i];
        }
        
        return ans;
    }
};
