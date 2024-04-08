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
    int minimumLevels(std::vector<int>& possible) {
        int n = possible.size();
        std::vector<int> psum(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + (possible[i] == 1 ? 1 : -1);
        }
        
        int ans = n;
        for(int i = 0; i < n - 1; i++) {
            if(psum[i + 1] > psum[n] - psum[i + 1]) {
                ans = std::min(ans, i + 1);
            }
        }
        
        return ans == n ? -1 : ans;
    }
};
