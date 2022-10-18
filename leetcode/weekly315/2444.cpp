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
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0LL;
        int n = nums.size();
        vector<int> nxt_min(n, n);
        vector<int> nxt_max(n, n);

        nxt_min[n - 1] = nums[n - 1] == minK ? n - 1 : n;
        nxt_max[n - 1] = nums[n - 1] == maxK ? n - 1 : n;
        for(int i = n - 2; i >= 0; i--) {
            nxt_min[i] = nums[i] == minK ? i : nxt_min[i + 1];
            nxt_max[i] = nums[i] == maxK ? i : nxt_max[i + 1];
        }
        
        for(int i = 0, j = 0; i < n; i++) {
            while(j < n && nums[j] >= minK && nums[j] <= maxK) {
                j++;
            }
            
            if(nums[i] >= minK && nums[i] <= maxK && nxt_min[i] < j && nxt_max[i] < j) {
                ans += j - max(nxt_min[i], nxt_max[i]);
            }
            
            if(i == j) {
                j++;
            }
        }
        
        return ans;
    }
};
