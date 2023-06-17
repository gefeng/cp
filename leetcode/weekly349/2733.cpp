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
    int findNonMinOrMax(std::vector<int>& nums) {
        int min_v = 100;
        int max_v = 0;
        for(int x : nums) {
            min_v = std::min(min_v, x);
            max_v = std::max(max_v, x);
        }
        
        int ans = -1;
        for(int x : nums) {
            if(x != min_v && x != max_v) {
                ans = x;
                break;
            }
        }
        
        return ans;
    }
};
