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
    int returnToBoundaryCount(std::vector<int>& nums) {
        int ans = 0;
        int p = 0;
        for(int x : nums) {
            p += x;
            if(p == 0) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
