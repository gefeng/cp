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
    bool isGood(std::vector<int>& nums) {
        int n = nums.size() - 1;
        
        if(n == 0) {
            return false;
        }
        
        std::vector<int> cnt(n + 1, 0);
        for(int x : nums) {
            if(x > n) {
                return false;
            }
            cnt[x] += 1;
        }
        
        for(int i = 1; i <= n; i++) {
            if(i == n) {
                if(cnt[i] != 2) {
                    return false;
                }
            } else {
                if(cnt[i] != 1) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
