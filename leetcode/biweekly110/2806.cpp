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
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int ans = 100;
        int min_v = 100;
        for(int i = 0; i <= 10; i++) {
            int x = abs(i * 10 - purchaseAmount);
            if(x < min_v) {
                min_v = x;
                ans = 100 - i * 10;
            } else if(x == min_v) {
                ans = std::min(ans, 100 - i * 10);
            }
        }
        
        return ans;
    }
};
