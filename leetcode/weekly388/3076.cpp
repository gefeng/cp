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
    std::vector<std::string> shortestSubstrings(std::vector<std::string>& arr) {
        int n = arr.size();
        std::map<std::string, int> s;
        for(std::string& t : arr) {
            int m = t.size();
            std::set<std::string> seen;
            for(int len = 1; len <= m; len++) {
                for(int i = 0; i <= m - len; i++) {
                    seen.insert(t.substr(i, len));
                }
            }
            
            for(const std::string& x : seen) {
                s[x] += 1;
            }
        }
        
        std::vector<std::string> ans(n, "");
        for(int j = 0; j < n; j++) {
            std::string& t = arr[j];
            int m = t.size();
            for(int len = 1; len <= m; len++) {
                std::string best = "";
                for(int i = 0; i <= m - len; i++) {
                    std::string ss = t.substr(i, len);
                    if(s[ss] == 1) {
                        best = best.empty() || ss < best ? ss : best;
                    }
                }
                if(best.size() == len) {
                    ans[j] = best;
                    break;
                }
            }
        }
        
        return ans;
    }
};
