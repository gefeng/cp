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
    int maximumPrimeDifference(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        auto is_prime = [](int x) {
            if(x == 1) {
                return false;
            } 
            for(int f = 2; f * f <= x; f++) {
                if(x % f == 0) {
                    return false;
                }
            }
            return true;
        };
        
        int first = -1;
        int last = -1;
        for(int i = 0; i < n; i++) {
            if(is_prime(nums[i])) {
                if(first == -1) {
                    first = i;
                } 
                last = i;
            }
        }
        
        return last - first;
    }
};
