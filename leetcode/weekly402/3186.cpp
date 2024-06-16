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
    long long maximumTotalDamage(std::vector<int>& power) {
        int n = power.size();
        
        std::sort(power.begin(), power.end());
        
        std::vector<std::pair<int, int>> a;
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && power[i] == power[j]) {
                i += 1;
            }
            a.emplace_back(power[j], i - j);
        }
        
        n = a.size();
        int64_t x = 0;
        int64_t y = 0;
        int64_t z = 0;
        for(int i = 0; i < n; i++) {
            int64_t nz = 0;
            auto [p, f] = a[i];
            
            if(i == 0) {
                nz = std::max(nz, (int64_t)p * f);
            } else {
                if(a[i - 1].first + 1 != p && a[i - 1].first + 2 != p) {
                    nz = std::max(nz, z + (int64_t)p * f);
                }
                
                if(i == 1 || (i - 2 >= 0 && a[i - 2].first + 2 != p)) {
                    nz = std::max(nz, y + (int64_t)p * f);
                }
                
                if(i == 2 || i - 3 >= 0) {
                    nz = std::max(nz, x + (int64_t)p * f);
                }
            }
        
            x = std::max(x, y);
            y = std::max(y, z);
            z = nz;
        } 
        
        return std::max(std::max(x, y), z);
    }
};
