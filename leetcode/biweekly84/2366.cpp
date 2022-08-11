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
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        int last = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= last) {
                last = nums[i];
            } else {
                ans += (nums[i] - 1) / last;
                if(nums[i] % last != 0) {
                    last = nums[i] / ((nums[i] + last - 1) / last);
                }
            }
        }
        
        return ans;
    }
};
