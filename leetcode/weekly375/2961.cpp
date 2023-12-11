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
    std::vector<int> getGoodIndices(std::vector<std::vector<int>>& variables, int target) {
        std::vector<int> ans;
        int n = variables.size();
        for(int j = 0; j < n; j++) {
            std::vector<int>& v = variables[j];
            int a = v[0];
            int b = v[1];
            int c = v[2];
            int m = v[3];
            
            int x = 1;
            for(int i = 0; i < b; i++) {
                x *= a;
                x %= 10;
            }
            
            int y = 1;
            for(int i = 0; i < c; i++) {
                y *= x;
                y %= m;
            }
            
            if(y == target) {
                ans.push_back(j);
            }
        }
        
        return ans;
    }
};
