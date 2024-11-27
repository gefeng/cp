#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(1e9);

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int ans = INF;
        int n = nums.size();
        
        for(int size = l; size <= r; size++) {
            int sum = 0;
            for(int i = 0, j = 0; j < n; j++) {
                sum += nums[j];
                if(j - i + 1 > size) {
                    sum -= nums[i++];
                }
                if(j - i + 1 == size) {
                    if(sum > 0) {
                        ans = std::min(ans, sum);
                    }
                }
            }   
        }
        
        return ans == INF ? -1 : ans;
    }
};
