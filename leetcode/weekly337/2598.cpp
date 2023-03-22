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
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                nums[i] += (abs(nums[i]) + value - 1) / value * value;
            }
        }
        
        vector<vector<int>> group(value);
        for(int i = 0; i < n; i++) {
            group[nums[i] % value].push_back(nums[i]);
        }
        
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            int r = i % value;
            if(group[r].empty()) {
                break;
            }
            ans += 1;
            group[r].pop_back();
        }
        
        return ans;
    }
};
