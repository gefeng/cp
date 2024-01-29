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
    int countKeyChanges(std::string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && std::tolower(s[i]) == std::tolower(s[j])) {
                i += 1;
            }
            
            ans += 1;
        }
        
        return ans - 1;
    }
};
