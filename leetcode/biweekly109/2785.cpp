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
    std::string sortVowels(std::string s) {
        int n = s.size();
        std::string v = "aeiouAEIOU";
        std::string t = "";
        
        for(char c : s) {
            if(v.find(c) != std::string::npos) {
                t.push_back(c);
            }        
        }
        
        std::sort(t.begin(), t.end());
        
        std::string ans = "";
        for(int i = 0, j = 0; i < n; i++) {
            if(v.find(s[i]) != std::string::npos) {
                ans.push_back(t[j++]);
            } else {
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};
