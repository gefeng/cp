#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

class Solution {
public:
    long long minimumCost(std::string source, std::string target, std::vector<std::string>& original, std::vector<std::string>& changed, std::vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        
        std::map<std::string, int> m_id;
        int id = 0;
        for(std::string& s : original) {
            m_id[s];
        }
        
        for(std::string& s : changed) {
            m_id[s];
        }
        
        for(auto& [_, v] : m_id) {
            v = id++;
        }
        
        std::vector<std::vector<int64_t>> best(id, std::vector<int64_t>(id, INF));
        for(int i = 0; i < id; i++) {
            best[i][i] = 0; 
        }
        
        for(int i = 0; i < m; i++) {
            int u = m_id[original[i]];
            int v = m_id[changed[i]];
            best[u][v] = std::min(best[u][v], (int64_t)cost[i]);
        }
        
        for(int k = 0; k < id; k++) {
            for(int i = 0; i < id; i++) {
                for(int j = 0; j < id; j++) {
                    if(best[i][k] != INF && best[k][j] != INF) {
                        best[i][j] = std::min(best[i][j], best[i][k] + best[k][j]);
                    }
                }
            }
        }
        
        std::vector<int> len;
        for(int i = 0; i < m; i++) {
            len.push_back(original[i].size());
        }
        
        std::sort(len.begin(), len.end());
        len.erase(std::unique(len.begin(), len.end()), len.end());
        
        std::vector<int64_t> dp(n + 1, INF);
        
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            if(source[i - 1] == target[i - 1]) {
                dp[i] = std::min(dp[i], dp[i - 1]);
            }
            for(int l : len) {
                if(i - l >= 0 && dp[i - l] != INF) {
                    std::string s = source.substr(i - l, l);
                    std::string t = target.substr(i - l, l);
                    
                    if(m_id.find(s) != m_id.end() && m_id.find(t) != m_id.end()) {
                        int u = m_id[s];
                        int v = m_id[t];
                        if(best[u][v] != INF) {
                            dp[i] = std::min(dp[i], dp[i - l] + best[u][v]);
                        }
                    }
                }
            }
        }
        
        return dp[n] == INF ? -1 : dp[n];
    }
};
