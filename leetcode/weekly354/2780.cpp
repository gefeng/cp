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
    int minimumIndex(std::vector<int>& nums) {
        std::map<int, int> m;
        int n = nums.size();
        
        for(int x : nums) {
            m[x] += 1;    
        }
        
        int dom = 0;
        int freq = 0;
        for(auto [k, v] : m) {
            if(v * 2 > n) {
                dom = k;
                freq = v;
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == dom) {
                cnt += 1;
            }
            if(cnt * 2 > i + 1 && (freq - cnt) * 2 > n - 1 - i) {
                return i;
            }
        }
        
        return -1;
    }
};
