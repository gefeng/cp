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
    int smallestNumber(int n) {
        int ans = 1;
        while(ans - 1 < n) {
            ans *= 2;
        }
        
        return ans - 1;
    }
};
