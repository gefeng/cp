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
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = (int)2e9;
        int ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            LL delta = 0LL;
            for(int i = n - 1; i > 0; i--) {
                LL cur_v = nums[i] + delta;
                if(cur_v > mid) {
                    delta = cur_v - mid;
                } else {
                    delta = 0LL;
                }
            }
            
            if(delta + nums[0] <= mid) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
