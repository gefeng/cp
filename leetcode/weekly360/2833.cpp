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
    int furthestDistanceFromOrigin(std::string moves) {
        int n = moves.size();
        int d1 = 0;
        int d2 = 0;
        for(int i = 0; i < n; i++) {
            if(moves[i] == 'L' || moves[i] == '_') {
                d1 += 1;
            } else {
                d1 -= 1;
            }
            
            if(moves[i] == 'R' || moves[i] == '_') {
                d2 += 1;
            } else {
                d2 -= 1;
            }
        }
        
        return std::max(d1, d2);
    }
};
