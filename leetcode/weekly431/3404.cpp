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
    int gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    
    long long numberOfSubsequences(std::vector<int>& nums) {
        int n = nums.size();
        int64_t ans = 0;
        
        std::map<std::pair<int, int>, std::vector<int>> m;
        for(int i = 0; i < n; i++) {
            for(int j = i + 2; j < n; j++) {
                int g = gcd(nums[j], nums[i]);
                m[{nums[j] / g, nums[i] / g}].push_back(i);
            }
        }
        
        for(auto& [_, a] : m) {
            std::sort(a.begin(), a.end());
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 2; j < n; j++) {
                int g = gcd(nums[i], nums[j]);
                std::pair<int, int> key = {nums[i] / g, nums[j] / g};
                if(m.find(key) != m.end()) {
                    std::vector<int>& a = m[key];
                    auto it = std::lower_bound(a.begin(), a.end(), j + 2);
                    ans += a.end() - it;
                }
            }
        }
        
        return ans;
    }
};
