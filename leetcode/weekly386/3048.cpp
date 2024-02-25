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
    int earliestSecondToMarkIndices(std::vector<int>& nums, std::vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        
        int lo = 1;
        int hi = m;
        int ans = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            std::vector<int> last(n, -1);
            for(int i = 0; i < mid; i++) {
                last[changeIndices[i] - 1] = i + 1;
            }
            
            bool ok = true;
            std::vector<std::pair<int, int>> a(n);
            for(int i = 0; i < n; i++) {
                if(last[i] == -1) {
                    ok = false;
                    break;
                }
                a[i] = {last[i], i};
            }
            if(!ok) {
                lo = mid + 1;
                continue;
            }
            
            std::sort(a.begin(), a.end());
            
            int64_t t = 0;
            for(auto [s, i] : a) {
                t += nums[i];
                if(t >= s) {
                    ok = false;
                    break;
                }
                t += 1;
            }
            
            if(ok) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
