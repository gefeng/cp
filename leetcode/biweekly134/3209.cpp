#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        int64_t ans = 0;
        
        std::array<int, 30> a;
        a.fill(INF);
        
        for(int l = 0, r = 0; r < n; r++) {
            bool ok = true;
            for(int i = 0; i < 30; i++) {
                if((k & (1 << i)) && !(nums[r] & (1 << i))) {
                    ok = false;
                    break;
                }
            }
            
            if(!ok) {
                l = r + 1;
                a.fill(INF);
            } else {
                int j = INF;
                for(int i = 0; i < 30; i++) {
                    if(!(nums[r] & (1 << i))) {
                        a[i] = r;
                    }
                }
                
                bool good = true;
                for(int i = 0; i < 30; i++) {
                    if((nums[r] & (1 << i)) && !(k & (1 << i))) {
                        if(a[i] == INF) {
                            j = INF;
                            good = false;
                            break;
                        }
                        j = std::min(j, a[i]);
                        good = false;
                    }
                }
                
                if(good) {
                    ans += r - l + 1;
                } else {
                    if(j != INF) {
                        ans += r - l + 1 - (r - j);
                    }
                }
            }
        }
        
        return ans;
    }
};
