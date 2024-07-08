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
    std::string getEncryptedString(std::string s, int k) {
        std::string ans = "";
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            ans.push_back(s[(i + k) % n]);
        }
        
        return ans;
    }
};
