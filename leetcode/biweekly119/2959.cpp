#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, std::vector<std::vector<int>>& roads) {
        int ans = 0;
        for(int i = 0; i < (1 << n); i++) {
            std::vector<int> act(n, 0);
            for(int v = 0; v < n; v++) {
                if(i & (1 << v)) {
                    act[v] = 1;
                }
            }
            
            std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
            for(auto& e : roads) {
                if(act[e[0]] && act[e[1]]) {
                    dist[e[0]][e[1]] = std::min(dist[e[0]][e[1]], e[2]);
                    dist[e[1]][e[0]] = std::min(dist[e[1]][e[0]], e[2]);
                }
            }
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == j && act[i]) {
                        dist[i][j] = 0;
                    }
                }
            }
            
            for(int k = 0; k < n; k++) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if(act[k] && act[i] && act[j] && dist[i][k] != INF && dist[k][j] != INF) {
                            dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
            
            int max_d = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(act[i] && act[j]) {
                        max_d = std::max(max_d, dist[i][j]);
                    }
                }
            }
            
            if(max_d != INF && max_d <= maxDistance) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
