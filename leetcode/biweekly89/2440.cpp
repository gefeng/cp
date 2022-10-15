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
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int ans = 0;
        int n = nums.size();
        
        int sum = 0;
        for(int x : nums) {
            sum += x;
        }
        
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        for(int f = 1; f <= sum; f++) {  
            if(sum % f == 0) {
                int t = sum / f;
                if(f == dfs(g, nums, t, 0, -1).second) {
                    ans = max(ans, f - 1);
                }
            }
        }
        
        return ans;
    }
    
    pair<int, int> dfs(vector<vector<int>>& g, vector<int>& nums, int t, int cur, int p) {
        int sum = nums[cur];
        int rem = 0;
        
        for(int nei : g[cur]) {
            if(nei != p) {
                pair<int, int> res = dfs(g, nums, t, nei, cur);
                sum += res.first;
                rem += res.second;
            }
        }
        
        if(sum - rem * t == t) {
            rem++;
        }
        
        return {sum, rem};
    }
};
