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
    std::vector<int> resultArray(std::vector<int>& nums) {
        std::vector<int> a;
        std::vector<int> b;
        
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        
        int n = nums.size();
        for(int i = 2; i < n; i++) {
            if(a.back() > b.back()) {
                a.push_back(nums[i]);
            } else {
                b.push_back(nums[i]);
            }
        }
        
        std::vector<int> ans;
        for(int x : a) {
            ans.push_back(x);
        }
        for(int x : b) {
            ans.push_back(x);
        }
        return ans;
    }
};
