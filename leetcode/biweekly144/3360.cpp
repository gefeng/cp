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
    bool canAliceWin(int n) {
        int t = 0;
        int s = 10;
        while(n >= s && s) {
            n -= s;
            s -= 1;
            t ^= 1;
        }
        
        return t == 1;
    }
};
