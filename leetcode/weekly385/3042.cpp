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
    int countPrefixSuffixPairs(std::vector<std::string>& words) {
        int ans = 0;
        int n = words.size();
        
        auto is_ok = [](std::string& s, std::string t) {
            if(t.find(s) != 0) {
                return false;
            } 
            
            int i = s.size() - 1;
            for(int j = t.size() - 1; i >= 0 && j >= 0; i--, j--) {
                if(s[i] != t[j]) {
                    return false;
                }
            }
            return i < 0;
        };
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(is_ok(words[i], words[j])) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};
