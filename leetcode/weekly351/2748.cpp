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
    int countBeautifulPairs(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        auto is_good = [&](int x, int y) {
            int first = 0;
            int last = y % 10;
            while(x) {
                first = x % 10;
                x /= 10;
            }    
            
            return gcd(first, last) == 1;
        };
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(is_good(nums[i], nums[j])) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
    
    int gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
};
