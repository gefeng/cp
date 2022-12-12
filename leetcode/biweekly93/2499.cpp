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
    using LL = long long;
    const int MAX = (int)1e5;
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        LL ans = 0LL;
        
        vector<int> freq(MAX + 1, 0);
        int tot = 0;
        for(int i = 0; i < n; i++) {
            if(nums1[i] == nums2[i]) {
                freq[nums1[i]] += 1;
                ans += i;
                tot += 1;
            }
        }
        
        int dominate = 0;
        for(int i = 1; i <= MAX; i++) {
            if(freq[i] > tot / 2) {
                dominate = i;
                break;
            }
        }
        
        if(dominate) {
            for(int i = 0; i < n && freq[dominate] > tot / 2; i++) {
                if(nums1[i] != nums2[i] && nums2[i] != dominate && nums1[i] != dominate) {
                    tot += 1;
                    ans += i;
                }
            }
        }
        
        if(freq[dominate] > tot / 2) {
            return -1; 
        }
        
        return ans;
    }
};
