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
    int minimumAddedCoins(std::vector<int>& coins, int target) {
        int ans = 0;
        int n = coins.size();
        std::sort(coins.begin(), coins.end());
        
        int i = 0;
        int can_make = 0;
        while(can_make < target) {
            if(i < n && can_make + 1 == coins[i]) {
                can_make += coins[i++];
            } else if(i < n && can_make >= coins[i]) {
                can_make += coins[i++];
            } else {
                ans += 1;
                can_make += can_make + 1;
            }
        }
        
        
        return ans;
    }
};
