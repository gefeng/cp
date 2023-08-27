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
    int minOperations(std::vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        
        std::map<int, int> m;
        for(int x : nums) {
            m[x] += 1;
        }
        
        std::array<int, 32> cnt = {};
        for(int x : nums) {
            for(int i = 0; i < 31; i++) {
                if(x & (1 << i)) {
                    cnt[i] += 1;
                    break;
                }
            }
        }
        
        int t = target;
        while(t != 0) {
            int b = 0;
            for(int i = 0; i < 31; i++) {
                if(t & (1 << i)) {
                    b = i;
                    break;
                }
            }

            if(cnt[b] != 0) {
                cnt[b] -= 1;
                t ^= 1 << b;
                continue;
            }
            
            int x = 1 << b;
            for(int i = b - 1; i >= 0 && x; i--) {
                int f = cnt[i];
                while(x >= (1 << i) && f) {
                    x -= 1 << i;
                    f -= 1;
                }
            }
            
            if(x == 0) {
                x = 1 << b; 
                for(int i = b - 1; i >= 0 && x; i--) {
                    while(x >= (1 << i) && cnt[i]) {
                        x -= 1 << i;
                        cnt[i] -= 1;
                    }
                }
                t ^= 1 << b;
            } else {
                int hb = -1;
                x = 1 << b;
                for(int i = b + 1; i < 31; i++) {
                    if(cnt[i]) {
                        hb = i;
                        break;
                    }
                }

                if(hb == -1) {
                    return -1;
                }
                
                while((1 << hb) != x) {
                    cnt[hb] -= 1;
                    hb -= 1;
                    cnt[hb] += 2;
                    ans += 1;
                }
            
                cnt[b] -= 1;
                t ^= 1 << b;
            }
        }
        
        return ans;
    }
};
