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
    int missingInteger(std::vector<int>& nums) {
        int n = nums.size();
        std::set<int> s;
        for(int x : nums) {
            s.insert(x);
        }
        
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] - nums[i - 1] != 1) {
                break;
            }
            
            sum += nums[i];
        }
    
        
        for(int i = 1; i <= 5000; i++) {
            if(s.find(i) == s.end() && i >= sum) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
