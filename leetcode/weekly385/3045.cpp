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
    std::vector<int> z_function(std::string s) {
        int n = s.size();
        std::vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = std::min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    long long countPrefixSuffixPairs(std::vector<std::string>& words) {
        int64_t ans = 0;        
        std::map<std::string, int> m;

        for(std::string& s : words) {
            int n = s.size();
            
            std::vector<int> save(n + 1, 0);
            std::vector<int> z = z_function(s);
            
            std::string t = "";
            for(int i = 0; i < n; i++) {
                t.push_back(s[i]);
                if(m.find(t) != m.end()) {
                    save[i + 1] = m[t];
                }
            }
            
            for(int i = 0; i < n; i++) {
                if(z[i] == n - i) {
                    ans += save[z[i]];
                }
            }
            
            if(m.find(s) != m.end()) {
                ans += m[s];
            }
            
            m[s] += 1;
        }
        
        return ans;
    }
};
