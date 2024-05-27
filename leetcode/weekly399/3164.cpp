#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = (int)1e6;

class Solution {
public:
    long long numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        int64_t ans = 0;
        
        std::unordered_map<int, int> m1;
        std::unordered_map<int, int> m2;
        for(int x : nums1) {
            m1[x] += 1;
        }
        
        for(int x : nums2) {
            m2[x] += 1;
        }
        
        for(auto [v, f] : m2) {
            int x = v * k;
            for(int j = x; j <= MAX; j += x) {
                if(m1.find(j) != m1.end()) {
                    ans += (int64_t)m1[j] * f;
                }
            }
        }
        
        return ans;
    }
};
