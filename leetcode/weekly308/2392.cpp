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

using namespace std;

class Solution {
public:
     vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> empty_matrix;
        vector<vector<int>> ans(k, vector<int>(k, 0));
        
        vector<int> row_info = topo(k, rowConditions);
        vector<int> col_info = topo(k, colConditions);
        
        if(row_info.empty() || col_info.empty()) {
            return empty_matrix;
        }
           
        for(int i = 1; i <= k; i++) {
            ans[row_info[i]][col_info[i]] = i;
        }
        
        return ans;
    }
    
    vector<int> topo(int k, vector<vector<int>>& cond) {
        vector<vector<int>> g(k + 1);
        vector<int> indegree(k + 1, 0);
        vector<int> empty_res;
        vector<int> res(k + 1, 0);
        
        for(vector<int>& v : cond) {
            g[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }
        
        queue<int> q;
        for(int i = 1; i <= k; i++) {
            if(!indegree[i]) {
                q.push(i);
            }
        }
        
        int cur = 0;
        while(!q.empty()) {
            int top = q.front();
            q.pop();

            res[top] = cur++;
            
            for(int nei : g[top]) {
                if(--indegree[nei] == 0) {
                    q.push(nei);
                }
            } 
        }
        
        if(cur < k) {
            return empty_res;
        }
        return res;
    }
};
