#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int m = nums1.size();
        int n = nums2.size();
        
        if(m & 1) {
            for(int x : nums2) {
                ans ^= x;
            }
        }
        if(n & 1) {
            for(int x : nums1) {
                ans ^= x;
            }
        }
        
        return ans;
    }
};
