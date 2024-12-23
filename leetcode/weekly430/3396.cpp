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
    int minimumOperations(std::vector<int>& nums) {
        int n = nums.size();
        std::array<int, 101> freq = {};
        
        for(int x : nums) {
            freq[x] += 1;
        }
        
        int ans = 0;
        bool end = true;
        for(int x : freq) {
            if(x > 1) {
                end = false;
                break;
            }
        }
        if(end) {
            return ans;
        }
        
        for(int i = 0; i < n; i += 3) {
            end = true;
            for(int j = 0; j < 3; j++) {
                if(i + j < n) {
                    freq[nums[i + j]] -= 1;
                }
            }
            ans += 1;
            
            for(int x : freq) {
                if(x > 1) {
                    end = false;
                    break;
                }
            }
            if(end) {
                break;
            }
        }
        
        return ans;
    }
};
