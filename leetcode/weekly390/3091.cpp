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
    int minOperations(int k) {
        int ans = k;
        
        for(int i = 0; i < k; i++) {
            int v = i + 1;
            if(v >= k) {
                ans = std::min(ans, i);
            } else {
                ans = std::min(ans, i + (k - 1) / v);
            }
        }
        
        return ans;
    }
};
