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
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        
        array<int, 32> cnt{0};
        for(int l = n - 1, r = n - 1; l >= 0; l--) {
            for(int i = 0; i < 32; i++) {
                if(nums[l] & (1 << i)) {
                    cnt[i]++;
                }
            }
            while(r > l) {
                bool can_remove = true;
                int x = nums[r];
                for(int i = 0; i < 32; i++) {
                    if((x & (1 << i)) && cnt[i] == 1) {
                        can_remove = false;
                        break;
                    }
                }
                
                if(can_remove) {
                    for(int i = 0; i < 32; i++) {
                        if(x & (1 << i)) {
                            cnt[i]--;
                        }
                    }
                    r--;
                } else {
                    break;
                }
            }
            
            ans[l] = r - l + 1;
        }
        
        return ans;
    }
};
