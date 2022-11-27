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
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        int p = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == k) {
                p = i;
                break;
            }
        }
        
        unordered_map<int, int> m;
        int cnt_1 = 0;
        int cnt_2 = 0;
        for(int i = p; i < n; i++) {
            if(nums[i] < k) {
                cnt_1 += 1;
            }
            if(nums[i] > k) {
                cnt_2 += 1;
            }
            m[cnt_1 - cnt_2] += 1;
        }
        
        cnt_1 = 0;
        cnt_2 = 0;
        for(int i = p; i >= 0; i--) {
            if(nums[i] < k) {
                cnt_1 += 1;
            }
            if(nums[i] > k) {
                cnt_2 += 1;
            } 
            
            int d = cnt_2 - cnt_1;
            if(m.find(d) != m.end()) {
                ans += m[d];
            }
            
            d = cnt_2 - cnt_1 - 1;
            if(m.find(d) != m.end()) {
                ans += m[d];
            }
        }
        
        return ans;
    }
};
