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
using LL = long long;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        LL sum = 0LL;
        LL ans = 0LL;
        for(int i = 0; i < n; i++) {
            if(nums1[i] == nums2[i]) {
                continue;
            }
            
            int d = abs(nums1[i] - nums2[i]);
            if(k == 0 || d % k) {
                return -1;
            }
            ans += d / k;
            if(nums1[i] > nums2[i]) {
                sum += d;
            } else {
                sum -= d;
            }
        }
        
        if(sum != 0LL) {
            return -1;
        }
        return ans / 2LL;
    }
};
