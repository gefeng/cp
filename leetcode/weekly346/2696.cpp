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
    int minLength(std::string s) {
        std::string stack = "";
        
        for(char c : s) {
            if(!stack.empty() && ((stack.back() == 'A' && c == 'B') || (stack.back() == 'C' && c == 'D'))) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        
        return stack.size();
    }
};
