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
    int winningPlayerCount(int n, std::vector<std::vector<int>>& pick) {
        std::vector<std::vector<int>> cnt(n, std::vector<int>(11, 0));

        for(auto& v : pick) { 
            cnt[v[0]][v[1]] += 1;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= 10; j++) {
                if(cnt[i][j] > i) {
                    ans += 1;
                    break;
                }
            }
        }

        return ans;
    }
};
