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
    int minIncrements(int n, std::vector<int>& cost) {
        int sz = (n + 1) / 2;
        int ans = 0;
        int p = n - 1;
        
        std::vector<int> pre_r;
        while(true) {
            std::vector<int> cur_r;
            
            for(int i = 0; i < sz; i++, p--) {
                cur_r.push_back(cost[p]);
            }
            
            std::reverse(cur_r.begin(), cur_r.end());
            
            for(int i = 0; i < sz; i++) {
                if(!pre_r.empty()) {
                    cur_r[i] += pre_r[2 * i];
                }
            }
            
            for(int i = 0; i < sz; i += 2) {
                int d = abs(cur_r[i] - cur_r[i + 1]);
                ans += d;
                cur_r[i] = std::max(cur_r[i], cur_r[i + 1]);
                cur_r[i + 1] = std::max(cur_r[i], cur_r[i + 1]);
            }
            
            sz /= 2;
            if(sz == 1) {
                break;
            }
            
            std::swap(cur_r, pre_r);
        } 
        
        return ans;
    }
};
