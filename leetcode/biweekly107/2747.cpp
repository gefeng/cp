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
    std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x, std::vector<int>& queries) {
        int m = queries.size();
        
        std::vector<std::pair<int, int>> qs(m);
        for(int i = 0; i < m; i++) {
            qs[i] = {queries[i], i};
        }
        
        auto cmp = [](const auto& a, const auto& b) {
            return a[1] < b[1];
        };
        
        std::sort(qs.begin(), qs.end());
        std::sort(logs.begin(), logs.end(), cmp);
        
        std::map<int, int> active_server;
        std::vector<int> ans(m);
        for(int i = 0, j = 0, k = 0; i < m; i++) {
            std::pair<int, int> q = qs[i];
            int l = q.first - x;
            int r = q.first;
            
            while(k < logs.size() && logs[k][1] <= r) {
                active_server[logs[k][0]] += 1;
                k += 1;
            }
            
            while(j < k && logs[j][1] < l) {
                if(--active_server[logs[j][0]] == 0) {
                    active_server.erase(logs[j][0]);
                }
                j += 1;
            }
            
            ans[q.second] = n - active_server.size();
        }
        
        return ans;
    }
};
