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
    std::string removeTrailingZeros(std::string num) {
        int i = num.size() - 1;
        while(i >= 0 && num[i] == '0') {
            i -= 1;
        }
        
        return num.substr(0, i + 1);
    }
};
