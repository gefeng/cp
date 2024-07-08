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
    std::vector<std::string> validStrings(int n) {
        std::vector<std::string> ans;
        
        for(int i = 0; i < (1 << n); i++) {
            std::string s(n, '0');
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    s[j] = '1';
                }
            }
            
            bool good = true;
            for(int j = 0; j < n - 1; j++) {
                if(s[j] == '0' && s[j + 1] == '0') {
                    good = false;
                }
            }
            
            if(good) {
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};
