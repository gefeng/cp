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
    std::string generateString(std::string str1, std::string str2) {
        int n = str1.size();
        int m = str2.size();
        std::string ans(n + m - 1, '.');
        
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    if(ans[i + j] == '.') {
                        ans[i + j] = str2[j];
                    } else {
                        if(ans[i + j] != str2[j]) {
                            return "";
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {
                bool ok = false;
                for(int j = 0; j < m; j++) {
                    if(ans[i + j] == '.' || ans[i + j] != str2[j]) {
                        ok = true;
                        break;
                    }
                } 
                if(!ok) {
                    return "";
                }
            }
        }
        
        for(int i = 0; i < n + m - 1; i++) {
            if(ans[i] == '.') {
                ans[i] = 'a';
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {
                bool same = true;
                for(int j = 0; j < m; j++) {
                    if(ans[i + j] != str2[j]) {
                        same = false;
                        break;
                    }
                }
                if(same) {
                    for(int j = 0; j < m; j++) {
                        if(i + j < n && str1[i + j] == 'T' && same) {
                            ans[i + j - 1] = 'b';
                            same = false;
                        }
                    }
                    if(same) {
                        ans[i + m - 1] = 'b';
                    }
                }
            }
        }
        
        return ans;
    }
};
