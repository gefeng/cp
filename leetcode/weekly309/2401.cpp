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
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int cur = nums[i];
            for(int j = i + 1; j < n; j++) {
                if((cur & nums[j]) != 0) {
                    break;
                }
                cur |= nums[j];
                ans = max(ans, j - i + 1);
            }
        }   
        
        return ans;
    }
};
