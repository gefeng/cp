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
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d1 = std::max(abs(sx - fx), abs(sy - fy));
        int d2 = abs(sx - fx) + abs(sy - fy);
        
        if(d1 > t) {
            return false;
        }
        
        if(t <= d2) {
            return true;
        }
        
        return t != 1;
    }
};
