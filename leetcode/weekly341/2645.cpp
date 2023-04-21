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
    int addMinimum(std::string word) {
        int ans = 0;
        std::string s = "abc";
        
        while(true) {
            int sz = s.size();
            int n = word.size();
            int j = 0;
            for(int i = 0; i < sz && j < n; ) {
                if(s[i] == word[j]) {
                    i += 1;
                    j += 1;
                } else {
                    i += 1;
                }
            }
            
            if(j == n) {
                ans = sz - n;
                break;
            }
            
            s.append("abc");
        }
        
        return ans;
    }
};
