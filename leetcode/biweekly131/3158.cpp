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
    int duplicateNumbersXOR(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        std::array<int, 51> seen{};
        for(int x : nums) {
            if(seen[x]) {
                ans ^= x;
            }
            seen[x] = 1;
        }
        
        return ans;
    }
};
