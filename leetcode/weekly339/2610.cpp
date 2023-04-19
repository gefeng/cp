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
    std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        
        std::array<int, 201> cnt = {};
        for(int x : nums) {
            cnt[x] += 1;
        }
        
        while(true) {
            std::vector<int> row;
            for(int i = 1; i <= 200; i++) {
                if(cnt[i]) {
                    row.push_back(i);
                    cnt[i] -= 1;
                }
            }
            
            if(row.empty()) {
                break;
            }
            
            ans.push_back(row);
        }
        
        return ans;
    }
};
