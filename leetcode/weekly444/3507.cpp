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
    int minimumPairRemoval(std::vector<int>& nums) {
        int ans = 0;
        
        auto is_inc = [](std::vector<int>& a) {
            int n = a.size();
            for(int i = 0; i < n - 1; i++) {
                if(a[i] > a[i + 1]) {
                    return false;
                }
            }
            return true;
        };
        
        while(!is_inc(nums)) {
            std::vector<int> nxt;
            int n = nums.size();
        
            int min_sum = INF;
            int j = -1;
            for(int i = 0; i < n - 1; i++) {
                int x = nums[i] + nums[i + 1];
                if(x < min_sum) {
                    min_sum = x;
                    j = i;
                }
            }
            
            for(int i = 0; i < j; i++) {
                nxt.push_back(nums[i]);
            }
            nxt.push_back(min_sum);
            for(int i = j + 2; i < n; i++) {
                nxt.push_back(nums[i]);
            }
            ans += 1;
            std::swap(nums, nxt);
        }
        
        return ans;
    }
};
