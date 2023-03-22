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
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        set<pair<int, int>> s;
        for(int i = 0; i < n; i++) {
            s.emplace(nums[i], i);
        }
        
        LL ans = 0LL;
        while(!s.empty()) {
            auto it = s.begin();
            int v = it->first;
            int i = it->second;
            
            ans += v;
            if(i > 0 && s.find({nums[i - 1], i - 1}) != s.end()) {
                s.erase({nums[i - 1], i - 1});
            }
            if(i < n - 1 && s.find({nums[i + 1], i + 1}) != s.end()) {
                s.erase({nums[i + 1], i + 1});
            }
            
            s.erase(it);
        }
        
        return ans;
    }
};
