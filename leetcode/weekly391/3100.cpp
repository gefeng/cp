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
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int cnt_empty = 0;
        while(true) {
            if(numBottles) {
                cnt_empty += 1;
                ans += 1;
                numBottles -= 1;
            } else {
                if(cnt_empty >= numExchange) {
                    cnt_empty -= numExchange;
                    numExchange += 1;
                    numBottles += 1;
                } else {
                    break;
                }
            }
        }
        
        return ans;
    }
};
