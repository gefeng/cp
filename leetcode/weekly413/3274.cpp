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
    bool checkTwoChessboards(std::string coordinate1, std::string coordinate2) {
        int x1 = coordinate1[0] - 'a';
        int y1 = coordinate1[1] - '0';
        int x2 = coordinate2[0] - 'a';
        int y2 = coordinate2[1] - '0';
        
        return (x1 % 2 == x2 % 2 && y1 % 2 == y2 % 2) || (x1 % 2 != x2 % 2 && y1 % 2 != y2 % 2);
    }
};
