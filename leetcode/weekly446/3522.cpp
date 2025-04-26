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
    long long calculateScore(std::vector<std::string>& instructions, std::vector<int>& values) {
        int64_t ans = 0;
        int n = instructions.size();
        
        std::vector<int> vis(n, 0);
        int p = 0;
        while(p >= 0 && p < n && !vis[p]) {
            std::string& s = instructions[p];
            if(s == "add") {
                ans += values[p];
                vis[p] = 1;
                p += 1;
            } else {
                vis[p] = 1;
                p += values[p];
            }
        }
        return ans;
    }
};
