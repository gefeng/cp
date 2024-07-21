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
    std::string losingPlayer(int x, int y) {
        int t = 0;
        std::string ans = "";
        while(true) {
            if(x == 0 || y < 4) {
                ans = t == 0 ? "Bob" : "Alice";
                break;
            }
            x -= 1;
            y -= 4;
            t ^= 1;
        }
        return ans;
    }
};
