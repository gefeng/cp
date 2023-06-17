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
    std::string smallestString(std::string s) {
        int n = s.size();
        bool found = false;
        for(int i = 0; i < n; i++) {
            if(s[i] != 'a') {
                while(i < n && s[i] != 'a') {
                    s[i] = s[i] - 1;
                    i += 1;
                }
                found = true;
                break;
            }
        }
        
        if(!found) {
            s[s.size() - 1] = 'z';
        }
        
        return s;
    }
};
