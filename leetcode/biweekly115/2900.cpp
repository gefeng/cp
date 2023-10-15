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
    std::vector<std::string> getWordsInLongestSubsequence(int n, std::vector<std::string>& words, std::vector<int>& groups) {
        std::vector<std::string> ans;
        
        int len1 = 0;
        int len2 = 0;
        
        for(int i = 0, cur = 0; i < n; i++) {
            if(groups[i] == cur) {
                cur ^= 1;
                len1 += 1;
            } 
        }
        
        for(int i = 0, cur = 1; i < n; i++) {
            if(groups[i] == cur) {
                cur ^= 1;
                len2 += 1;
            }
        }
        
        int x = 0;
        if(len1 < len2) {
            x = 1;
        }
        
        for(int i = 0; i < n; i++) {
            if(groups[i] == x) {
                x ^= 1;
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};
