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
    int minimumOperations(std::vector<int>& nums) {
        int ans = 0;
        for(int x : nums) {
            if(x % 3 != 0) {
                ans += 1;
            } 
        }
        return ans;
    }
};
