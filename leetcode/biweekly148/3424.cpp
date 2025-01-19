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
    long long minCost(std::vector<int>& arr, std::vector<int>& brr, long long k) {
        int n = arr.size();
        int64_t ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += std::abs(arr[i] - brr[i]);
        }
        
        int64_t cost = k;
        std::sort(arr.begin(), arr.end());
        std::sort(brr.begin(), brr.end());
        
        for(int i = 0; i < n; i++) {
            cost += std::abs(arr[i] - brr[i]);
        }
        
        ans = std::min(ans, cost);
        
        return ans;
    }
};
