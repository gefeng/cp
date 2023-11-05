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
    int findChampion(int n, std::vector<std::vector<int>>& edges) {
        std::vector<int> indegree(n, 0);
        
        for(auto& e : edges) {
            indegree[e[1]] += 1;
        }
        
        int cnt = 0;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                cnt += 1;
                ans = i;
            }
        }
        
        if(cnt == 1) {
            return ans;
        }
        return -1;
    }
};
