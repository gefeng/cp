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
    int findMinimumOperations(std::string s1, std::string s2, std::string s3) {
        int ans = -1;
        
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        int n = std::min(size1, std::min(size2, size3));
        
        for(int len = 1; len <= n; len++) {
            if(s1.substr(0, len) == s2.substr(0, len) && s2.substr(0, len) == s3.substr(0, len)) {
                int cnt = size1 - len + size2 - len + size3 - len;
                ans = ans == -1 ? cnt : std::min(ans, cnt);
            }
        }
        
        return ans;
    }
};
