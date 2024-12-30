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
    std::string answerString(std::string word, int numFriends) {
        std::string ans = "";
        int n = word.size();
        
        if(numFriends == 1) {
            return word;
        }
        
        if(numFriends == 2) {
            for(int i = 0; i < n - 1; i++) {
                ans = std::max(ans, std::max(word.substr(0, i + 1), word.substr(i + 1, n - 1 - i)));
            }
            return ans;
        }
        
        char max_c = 'a';
        for(int i = 0; i < n; i++) {
            max_c = std::max(max_c, word[i]);
        }
        
        for(int i = 0; i < n; i++) {
            if(word[i] == max_c) {
                ans = std::max(ans, word.substr(i, std::min(n - numFriends + 1, n - i)));
            }
        }
        
        return ans;
    }
};
