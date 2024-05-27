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
    int numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums1[i] % (k * nums2[j]) == 0) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
