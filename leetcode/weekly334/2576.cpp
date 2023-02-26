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
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n / 2; i++) {
            nums[i] *= 2;
        }
        
        int l = 0;
        int r = n / 2;
        while(l < n / 2 && r < n) {
            if(nums[l] <= nums[r]) {
                l += 1;
                r += 1;
            } else {
                r += 1;
            }
        }
        
        return l * 2;
    }
};
