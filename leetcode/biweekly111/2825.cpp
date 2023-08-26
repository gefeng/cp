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
    bool canMakeSubsequence(std::string str1, std::string str2) {
        int m = str1.size();
        int n = str2.size();
        
        int j = 0;
        for(int i = 0; i < m && j < n; i++) {
            if(str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 == str2[j] - 'a') {
                j += 1;
            }
        }
        
        return j == n;
    }
};
