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
    long long minDamage(int power, std::vector<int>& damage, std::vector<int>& health) {
        int n = damage.size();
        std::vector<std::pair<int, int>> a(n);
        
        for(int i = 0; i < n; i++) {
            a[i] = {damage[i], health[i]};
        }
        
        std::sort(a.begin(), a.end(), [&](const auto& x, const auto& y) {
            int64_t t1 = (x.second + power - 1) / power;
            int64_t t2 = (y.second + power - 1) / power;
            int64_t d1 = t1 * x.first + (t1 + t2) * y.first; 
            int64_t d2 = t2 * y.first + (t1 + t2) * x.first;
            return d1 < d2;
        });
        
        int64_t ans = 0;
        int64_t sec = 0;
        for(auto [d, h] : a) {
            sec += (h + power - 1) / power;
            ans += sec * d;
        }
        
        return ans;
    }
};
