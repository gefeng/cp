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
    long long minSum(std::vector<int>& nums1, std::vector<int>& nums2) {
        int64_t ans = -1;
        int64_t sum1 = 0;
        int64_t sum2 = 0;
        for(int x : nums1) {
            sum1 += x == 0 ? 1 : x;
        }
        
        bool zero = false;
        for(int x : nums2) {
            sum2 += x == 0 ? 1 : x;
            if(x == 0) {
                zero = true;
            }
        }
        
        if((sum1 >= sum2 && zero) || (sum1 == sum2 && !zero)) {
            ans = sum1;
        }
        
        sum1 = 0;
        sum2 = 0;
        zero = false;
        for(int x : nums2) {
            sum1 += x == 0 ? 1 : x;
        }
        for(int x : nums1) {
            sum2 += x == 0 ? 1 : x;
            if(x == 0) {
                zero = true;
            }
        }
        
        if((sum1 >= sum2 && zero) || (sum1 == sum2 && !zero)) {
            ans = ans == -1 ? sum1 : std::min(ans, sum1);
        }
        
        return ans;
    }
};
