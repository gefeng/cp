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
    std::string makeSmallestPalindrome(std::string s) {
        for(int l = 0, r = s.size() - 1; l < r; l += 1, r -= 1) {
            if(s[l] != s[r]) {
                if(s[l] > s[r]) {
                    s[l] = s[r];
                } else {
                    s[r] = s[l];
                }
            } 
        }
        
        return s;
    }
};
