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
    bool isPossibleToRearrange(std::string s, std::string t, int k) {
        int n = s.size();
        std::map<std::string, int> m;
        
        int size = n / k;
        for(int i = 0; i < n; i += size) {
            m[s.substr(i, size)] += 1;
        }
        
        for(int i = 0; i < n; i += size) {
            std::string st = t.substr(i, size);
            if(m.find(st) == m.end()) {
                return false;
            }
            if(--m[st] == 0) {
                m.erase(st);
            }
        }
        
        return true;
    }
};
