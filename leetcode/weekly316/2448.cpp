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
    long long minCost(vector<int>& nums, vector<int>& cost) {
        LL ans = (LL)1e18;
        int n = nums.size();
        vector<LL> psum_1(n + 1, 0LL);
        vector<LL> psum_2(n + 1, 0LL);
        
        vector<pair<int, int>> v(n, {0, 0});
        for(int i = 0; i < n; i++) {
            v[i] = {nums[i], cost[i]};
        }
        
        sort(v.begin(), v.end());
        
        for(int i = 1; i <= n; i++) {
            psum_1[i] = psum_1[i - 1] + v[i - 1].second;
            psum_2[i] = psum_2[i - 1] + (LL)v[i - 1].second * v[i - 1].first;
        }

        for(int i = 0; i < n; i++) {
            LL x = (psum_1[i + 1] - (psum_1[n] - psum_1[i + 1])) * v[i].first;
            LL y = psum_2[i + 1] - (psum_2[n] - psum_2[i + 1]);
            
            ans = min(ans, x - y);
        }
        
        return ans;
    }
};
