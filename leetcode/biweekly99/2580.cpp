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

const LL MOD = (LL)1e9 + 7LL;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();
        
        auto cmp = [](const auto& a, const auto& b) {
            return a[0] < b[0];
        };
        
        sort(ranges.begin(), ranges.end(), cmp);
        
        int cnt = 1;
        int l = ranges[0][0];
        int r = ranges[0][1];
        for(int i = 1; i < n; i++) {
            int cl = ranges[i][0];
            int cr = ranges[i][1];
            if(cl > r) {
                cnt += 1;
                l = cl;
                r = cr;
            } else {
                r = max(r, cr);
            }
        }
        
        LL ans = 1LL;
        for(int i = 0; i < cnt; i++) {
            ans *= 2;
            ans %= MOD;
        }
        
        return ans;
    }
};
