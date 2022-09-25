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
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        
        vector<bool> ok_1(n, false);
        vector<bool> ok_2(n, false);
        for(int i = 0; i < n; ) {
            int j = i;
            i++;
            while(i < n && nums[i] <= nums[i - 1]) {
                i++;
            }
            
            if(i - j >= k) {
                for(int p = j + k; p <= min(i, n - k); p++) {
                    ok_1[p] = true;
                }
            } 
        }
        
        for(int i = n - 1; i >= 0; ) {
            int j = i;
            i--;
            while(i >= 0 && nums[i] <= nums[i + 1]) {
                i--;
            }
            
            if(j - i >= k) {
                for(int p = j - k; p >= max(k, i); p--) {
                    ok_2[p] = true;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(ok_1[i] && ok_2[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
