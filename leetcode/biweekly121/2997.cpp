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
    int minOperations(std::vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        for(int x : nums) {
            sum ^= x;
        }
        
        for(int i = 0; i <= 30; i++) {
            int b1 = k & (1 << i);
            int b2 = sum & (1 << i);
            if(b1 != b2) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
