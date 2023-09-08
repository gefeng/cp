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
    int minimumTime(std::vector<int>& nums1, std::vector<int>& nums2, int x) {
        int n = nums1.size();
        std::vector<std::pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i].first = nums1[i];
            a[i].second = nums2[i];
        }
        
        std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            return x.second < y.second;
        });
        
        std::vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            std::vector<int> ndp(n + 1, 0);
            
            for(int j = 0; j <= i + 1; j++) {
                if(j <= i) {
                    ndp[j] = std::max(ndp[j], dp[j]);
                }
                
                if(j) {
                    ndp[j] = std::max(ndp[j], dp[j - 1] + a[i].first + a[i].second * j);
                }
            } 
            
            std::swap(dp, ndp);
        }
        
        int sum = 0;
        int delta = 0;
        for(int i = 0; i < n; i++) {
            sum += nums1[i];
            delta += nums2[i];
        }
        
        for(int i = 0; i <= n; i++) {
            if(sum - dp[i] <= x) {
                return i;
            }
            
            sum += delta;
        }
        
        return -1;
    }
};
