#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

const int INF = (int)1e9;

class Solution {
public:
    int minOperations(std::vector<int>& nums1, std::vector<int>& nums2) {
        int ans = INF;
        int n = nums1.size();
        
        auto solve = [&](std::vector<int> a, std::vector<int> b) {
            int cnt = 0;
            for(int i = 0; i < n - 1; i++) {
                if(a[i] > a.back()) {
                    std::swap(a[i], b[i]);
                    cnt += 1;
                }
            }

            bool ok = true;
            for(int i = 0; i < n - 1; i++) {
                if(b[i] > b.back() || a[i] > a.back()) {
                    ok = false;
                    break;
                }
            }
            return ok ? cnt : INF;
        };
        
        std::vector<int> a(nums1);
        std::vector<int> b(nums2);
        ans = std::min(ans, solve(a, b));
        ans = std::min(ans, solve(b, a));
        std::swap(a[n - 1], b[n - 1]);
        ans = std::min(ans, solve(a, b) + 1);
        ans = std::min(ans, solve(b, a) + 1);
        
        return ans == INF ? -1 : ans;
    }
};
