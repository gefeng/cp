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
    int minGroupsForValidAssignment(std::vector<int>& nums) {
        int n = nums.size();
        std::map<int, int> m;
        
        for(int x : nums) {
            m[x] += 1;
        }
        
        // find a x where f_i mod x == 0 or f_i mod x == 1;
        //x * c = f_i
        //x * c + 1 = f_i
        
        std::set<int> s;
        for(auto [_, f] : m) {
            s.insert(f);
        }
        
        int max_f = *s.rbegin();
        int x = 1;
        for(int i = 2; i <= max_f; i++) {
            bool ok = true;
            for(int f : s) {
                int cnt = (f + i - 1) / i;
                int rem = cnt * i - f;
                if(rem > cnt) {
                    ok = false;
                    break;
                }
            }
            
            if(ok) {
                x = i;
            }
        }
        
        int ans = 0;
        for(auto [_, f] : m) {
            ans += (f + x - 1) / x;
        }
        return ans;
    }
};
