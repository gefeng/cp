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
    long long flowerGame(int n, int m) {
        int64_t ans = 0;
        
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 1) {
                ans += m / 2;
            } else {
                ans += (m + 1) / 2;
            }
        }
        
        return ans;
    }
};
