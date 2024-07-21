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
    int minChanges(std::vector<int>& nums, int k) {
        int n = nums.size();
        int max_v = 0;
        int ans = INF;
        
        for(int l = 0, r = n - 1; l < r; l++, r--) {
            max_v = std::max(max_v, std::abs(nums[r] - nums[l]));
        }
        
        std::vector<std::vector<int>> a(max_v + 1);
        std::vector<std::pair<int, int>> b;
        for(int l = 0, r = n - 1; l < r; l++, r--) {
            a[std::abs(nums[l] - nums[r])].push_back(l);
            
            int max_d = std::max(std::max(nums[l], nums[r]), k - std::min(nums[l], nums[r]));
            b.emplace_back(max_d, l);
        }

        std::sort(b.begin(), b.end());
        
        for(int i = max_v, j = b.size() - 1; i >= 0; i--) {
            if(a[i].empty()) {
                continue;
            }
            
            int cost = 0;
            while(j >= 0 && b[j].first >= i) {
                j -= 1;
            }
            cost = (j + 1) * 2 + n / 2 - 1 - j - int(a[i].size());
            ans = std::min(ans, cost);
        }
        return ans;
    }
};
