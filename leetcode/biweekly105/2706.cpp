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
    int buyChoco(std::vector<int>& prices, int money) {
        std::sort(prices.begin(), prices.end());
        
        if(prices[0] + prices[1] > money) {
            return money;
        }
        
        return money - prices[0] - prices[1];
    }
};
