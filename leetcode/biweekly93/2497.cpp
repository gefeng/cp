#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> g(n);
        vector<int> sum(n, 0);
        
        for(auto& e : edges) {
            g[e[0]].push_back(vals[e[1]]);
            g[e[1]].push_back(vals[e[0]]);
            
            sum[e[0]] += vals[e[1]];
            sum[e[1]] += vals[e[0]];
        }

        int ans = -2e9;
        for(int i = 0; i < n; i++) {
            vector<int>& v = g[i];
            sort(v.begin(), v.end(), greater<int>());
            
            int sum = vals[i];
            ans = max(ans, sum);
            for(int j = 0; j < min(k, (int)v.size()); j++) {
                sum += v[j];
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};
