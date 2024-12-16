#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

constexpr double EPS = 1e-9;

class Solution {
public:
    double maxAmount(std::string initialCurrency, vector<vector<std::string>>& pairs1, std::vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        int n = pairs1.size();
        int m = pairs2.size();
        
        std::map<std::string, std::vector<std::pair<std::string, double>>> g1;
        std::map<std::string, std::vector<std::pair<std::string, double>>> g2;

        for(int i = 0; i < n; i++) {
            std::string& u = pairs1[i][0];
            std::string& v = pairs1[i][1];
            double w = rates1[i];
            g1[u].emplace_back(v, w);
            g1[v].emplace_back(u, 1.0 / w);
        }
        
        for(int i = 0; i < m; i++) {
            std::string& u = pairs2[i][0];
            std::string& v = pairs2[i][1];
            double w = rates2[i];
            g2[u].emplace_back(v, w);
            g2[v].emplace_back(u, 1.0 / w);
        }
        
        auto solve = [&](std::map<std::string, std::vector<std::pair<std::string, double>>>& g, std::string s, double sv) {
            std::priority_queue<std::pair<double, std::string>> pq;
            std::map<std::string, double> best;
            best[s] = sv;
            pq.emplace(sv, s);
            
            while(!pq.empty()) {
                auto [v, cur] = pq.top();
                pq.pop();
                
                if(best[cur] - v > EPS) {
                    continue;
                }
                
                for(auto& nei : g[cur]) {
                    std::string n_cur = nei.first;
                    double rate = nei.second;
                    double nv = v * rate;
                    if(nv - best[n_cur] > EPS) {
                        best[n_cur] = nv;
                        pq.emplace(nv, n_cur);
                    }
                }
            }
            
            return best;
        };
        
        double ans = 0.0;
        std::map<std::string, double> m1 = solve(g1, initialCurrency, 1.0);
        for(auto& [cur, v] : m1) {
            std::map<std::string, double> m2 = solve(g2, cur, v);
            if(m2.find(initialCurrency) != m2.end()) {
                ans = std::max(ans, m2[initialCurrency]);
            }
        }
        
        return ans;
    }
};
