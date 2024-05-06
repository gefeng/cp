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
    bool isValid(std::string word) {
        int n = word.size();
        if(n < 3) {
            return false;
        }
        
        int mask = 0;
        std::string s = "aeiouAEIOU";
        for(int i = 0; i < n; i++) {
            char c = word[i];
            if((c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
                return false;
            }
            if(s.find(c) != std::string::npos) {
                mask |= 1 << 0;
            } else {
                if(c < '0' || c > '9') {
                    mask |= 1 << 1;
                }
            }
        }
        
        return mask == 3;
    }
};
