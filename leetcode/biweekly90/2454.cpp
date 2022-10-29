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
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
    
        vector<pair<int, int>> p(n, {0, 0});
        for(int i = 0; i < n; i++) {
            p[i] = {-nums[i], i};
        }
        
        sort(p.begin(), p.end());
        
        set<int> s;
        for(auto& x : p) {
            auto it = s.lower_bound(x.second);
            
            if(it != s.end() && ++it != s.end()) {
                ans[x.second] = nums[*it];
            }
            
            s.insert(x.second);
        }
        
        return ans;
    }
};
