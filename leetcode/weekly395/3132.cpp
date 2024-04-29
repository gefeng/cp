#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

class Solution {
public:
    int minimumAddedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        int ans = INF;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                bool ok = true;
                int d = INF;
                for(int p1 = 0, p2 = 0; p1 < n; p1++) {
                    if(p1 == i || p1 == j) {
                        continue;
                    }
                    
                    if(d != INF && d != nums2[p2] - nums1[p1]) {
                        ok = false;
                        break;
                    }
                    
                    d = nums2[p2] - nums1[p1];
                    p2 += 1;
                }
                
                if(ok) {
                    ans = std::min(ans, d);
                }
            }
        }
        return ans;
    }
};
