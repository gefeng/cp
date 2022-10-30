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
using LL = long long;

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        
        unordered_map<string, pair<string, int>> p_m;
        unordered_map<string, LL> v_m;
        
        for(int i = 0; i < n; i++) {
            string x = creators[i];
            string y = ids[i];
            int c = views[i];
            
            v_m[x] += c;
            if(p_m.find(x) == p_m.end()) {
                p_m[x] = {y, c};
            } else {
                if(p_m[x].second < c) {
                    p_m[x] = {y, c};
                } else if(p_m[x].second == c && p_m[x].first > y) {
                    p_m[x] = {y, c};
                }
            }
        }
        
        LL max_v = 0;
        for(auto& [k, v] : v_m) {
            max_v = max(max_v, v);
        }
        
        vector<vector<string>> ans;
        for(auto& [k, v] : v_m) {
            if(v == max_v) {
                ans.emplace_back();
                ans.back().push_back(k);
                ans.back().push_back(p_m[k].first);
            }
        }
        
        return ans;
    }
};
