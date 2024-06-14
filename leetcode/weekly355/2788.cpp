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
    std::vector<std::string> splitWordsBySeparator(std::vector<std::string>& words, char separator) {
        std::vector<std::string> ans;
        
        for(std::string& s : words) {
            int n = s.size();
            std::string w = "";
            for(int i = 0; i < n; i++) {
                if(s[i] == separator) {
                    if(!w.empty()) {
                        ans.push_back(w);
                        w = "";
                    }
                } else {
                    w.push_back(s[i]);
                }
            }
            
            if(!w.empty()) {
                ans.push_back(w);
            }
        }
        
        return ans;
    }
};
