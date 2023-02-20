#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
    
        string s = "";
        char c = 'a';
        for(int i = 0; i < n; i++) {
            s.push_back('*');
        }
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                for(int j = i; j < n; j++) {
                    if(lcp[i][j]) {
                        if(c > 'z') {
                            return "";
                        }
                        s[j] = c;
                    }
                }
                c += 1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                return "";
            }
        }
        
        vector<vector<int>> m(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            if(s[i] == s[n - 1]) {
                m[i][n - 1] = 1;
                m[n - 1][i] = 1;
            }
        }
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                if(s[i] == s[j]) {
                    m[i][j] = m[i + 1][j + 1] + 1;
                }
            }
        }
        
        if(m == lcp) {
            return s;
        }
        return "";
    }
};
