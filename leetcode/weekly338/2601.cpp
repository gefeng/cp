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
    const int MAX = 1000;
public:
    bool primeSubOperation(std::vector<int>& nums) {
        int n = nums.size();
        
        std::vector<int> is_p(MAX + 1, true);
        is_p[1] = false;
        for(int i = 2; i <= MAX; i++) {
            if(is_p[i]) {
                for(int j = i + i; j <= MAX; j += i) {
                    is_p[j] = false;
                }
            }
        }
        
        std::vector<int> primes;
        for(int i = 2; i <= MAX; i++) {
            if(is_p[i]) {
                primes.push_back(i);
            }
        }
        
        int lb = 0;
        for(int i = 0; i < n; i++) {
            int min_v = MAX + 1;
            for(int p : primes) {
                if(p < nums[i] && nums[i] - p > lb) {
                    min_v = std::min(min_v, nums[i] - p);
                }
            }
            
            if(min_v != MAX + 1) {
                nums[i] = min_v;
            }
            
            lb = nums[i];
        }
        
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};
