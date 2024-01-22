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
    std::vector<int> beautifulIndices(std::string s, std::string a, std::string b, int k) {
        int n = s.size();
        std::vector<int> good;
        
        int m = b.size();
        for(int i = 0; i <= n - m; i++) {
            bool ok = true;
            for(int j = 0; j < m; j++) {
                if(s[i + j] != b[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                good.push_back(i);
            }
        }
        
        m = a.size();
        std::vector<int> ans;
        for(int i = 0; i <= n - m; i++) {
            bool ok = true;
            for(int j = 0; j < m; j++) {
                if(s[i + j] != a[j]) {
                    ok = false;
                    break;
                }
            }
            
            if(ok) {
                bool dist = false;
                auto it = std::upper_bound(good.begin(), good.end(), i);
                if(it != good.end()) {
                    if(std::abs(*it - i) <= k) {
                        dist = true;
                    }
                }
                if(it != good.begin()) {
                    it--;
                    if(std::abs(*it - i) <= k) {
                        dist = true;
                    }
                }
                
                if(dist) {
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};
