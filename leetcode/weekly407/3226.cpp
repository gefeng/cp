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
    int minChanges(int n, int k) {
        int ans = 0;
        
        for(int i = 0; i < 30; i++) {
            int b1 = n & (1 << i) ? 1 : 0;
            int b2 = k & (1 << i) ? 1 : 0;
            if(b1 == b2) {
                continue;
            }
            if(b1 == 0) {
                return -1;
            }
            ans += 1;
        }
        
        return ans;
    }
};
