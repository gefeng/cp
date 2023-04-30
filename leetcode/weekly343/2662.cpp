#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MAX = (LL)1e5;
constexpr LL INF = (LL)2e18;

class Solution {
public:
    int minimumCost(std::vector<int>& start, std::vector<int>& target, std::vector<std::vector<int>>& specialRoads) {
        if(start[0] == target[0] && start[1] == target[1]) {
            return 0;    
        }
        
        int m = specialRoads.size();
        std::set<LL> s;
        
        auto hashify = [](int x, int y) {
            return 1LL * x * MAX + y;
        };
        
        s.insert(hashify(start[0], start[1]));
        s.insert(hashify(target[0], target[1]));
        
        for(auto& r : specialRoads) {
            s.insert(hashify(r[2], r[3]));
        }
        
        int n = s.size();
        int generator = 0;
        std::map<LL, int> m1;
        std::map<int, LL> m2;
        for(LL v : s) {
            m1[v] = generator++;
            m2[generator - 1] = v;
        }

        std::vector<std::vector<LL>> dp(n, std::vector<LL>(n, INF));
        
        for(int i = 0; i < m; i++) {
            std::vector<int>& r1 = specialRoads[i];
            
            for(int j = 0; j < m; j++) {
                if(i != j) {
                    std::vector<int>& r2 = specialRoads[j];
                    
                    int u = m1[hashify(r1[2], r1[3])];
                    int v = m1[hashify(r2[2], r2[3])];
                    
                    dp[u][v] = std::min(dp[u][v], 1LL * abs(r1[2] - r2[2]) + abs(r1[3] - r2[3]));
                    dp[u][v] = std::min(dp[u][v], 1LL * abs(r1[2] - r2[0]) + abs(r1[3] - r2[1]) + r2[4]);
                }
            }
        }
        
        int st = m1[hashify(start[0], start[1])];
        int ed = m1[hashify(target[0], target[1])];
        for(auto& r : specialRoads) {
            int v = m1[hashify(r[2], r[3])];
            
            dp[st][v] = std::min(dp[st][v], 1LL * abs(start[0] - r[2]) + abs(start[1] - r[3]));
            dp[st][v] = std::min(dp[st][v], 1LL * abs(start[0] - r[0]) + abs(start[1] - r[1]) + r[4]);
            
            dp[v][ed] = std::min(dp[v][ed], 1LL * abs(r[2] - target[0]) + abs(r[3] - target[1]));
        }
        
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i != k && i != j && j != k) {
                        dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }
        
        return dp[m1[hashify(start[0], start[1])]][m1[hashify(target[0], target[1])]];
    }
};
