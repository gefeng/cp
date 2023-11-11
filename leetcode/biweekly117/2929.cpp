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
    long long distributeCandies(int n, int limit) {
        int64_t ans = 0;
        for(int i = 0; i <= std::min(n, limit); i++) {
            int x = n - i;
            if(x <= limit) {
                ans += x + 1;   
            } else if(x <= limit * 2) {
                ans += limit - std::max(0, x - limit) + 1;
            }
        }
        return ans;
    }
};
