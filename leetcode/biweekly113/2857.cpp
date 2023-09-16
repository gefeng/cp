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
    int countPairs(std::vector<std::vector<int>>& coordinates, int k) {
        std::unordered_map<int, std::unordered_map<int, int>> m;

        int64_t ans = 0;
        for(auto& p : coordinates) {
            for(int sum = 0; sum <= k; sum++) {
                int tx = sum ^ p[0];
                int ty = (k - sum) ^ p[1];
                if(m.find(tx) != m.end() && m[tx].find(ty) != m[tx].end()) {
                    ans += m[tx][ty];
                }
            }
            
            m[p[0]][p[1]] += 1;
        }
        
        return ans;
    }
};
