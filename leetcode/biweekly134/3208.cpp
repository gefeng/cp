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
    int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
        int ans = 0;
        int n = colors.size();
        
        for(int i = 0; i < n; i++) {
            colors.push_back(colors[i]);
        }
        
        for(int i = 0; i < n; i++) {
            int j = i;
            while(i + 1 < n * 2 && colors[i + 1] != colors[i]) {
                i += 1;
            }
            
            for(int s = j; s <= std::min(n - 1, i); s++) {
                if(s + k - 1 <= i) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
