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
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        
        int n = s.size();
        map<int, pair<int, int>> m;
        for(int i = 1; i <= 30; i++) {
            int x = 0;
            int d = 1;
            for(int l = 0, r = 0; r < n; r++) {
                x = x * 2 + s[r] - '0';
                if(r - l + 1 > i) {
                    x -= d * (s[l++] - '0');
                } else {
                    d *= 2;
                }
                
                if(r - l + 1 == i && m.find(x) == m.end()) {
                    m[x] = {l, r};
                }
            }
        }
        
        for(auto& q : queries) {
            int t = q[0] ^ q[1];
            ans.emplace_back();
            if(m.find(t) == m.end()) {
                ans.back().push_back(-1);
                ans.back().push_back(-1);
            } else {
                ans.back().push_back(m[t].first);
                ans.back().push_back(m[t].second);
            }
        }
        
        return ans;
    }
};
