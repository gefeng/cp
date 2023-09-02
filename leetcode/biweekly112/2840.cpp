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
    bool checkStrings(std::string s1, std::string s2) {
        int n = s1.size();
        std::string a, b, c, d = "";
        for(int i = 0; i < n; i += 2) {
            a.push_back(s1[i]);
            c.push_back(s2[i]);
        }
        
        for(int i = 1; i < n; i += 2) {
            b.push_back(s1[i]);
            d.push_back(s2[i]);
        }
        
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::sort(c.begin(), c.end());
        std::sort(d.begin(), d.end());
        
        int sz = a.size();
        for(int i = 0; i < sz; i++) {
            if(a[i] != c[i]) {
                return false;
            }
        }
        
        sz = b.size();
        for(int i = 0; i < sz; i++) {
            if(b[i] != d[i]) {
                return false;
            }
        }
        
        return true;
    }
};
