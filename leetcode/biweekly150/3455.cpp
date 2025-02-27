#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

class Solution {
public:
    std::vector<int> prefix_function(std::string s) {
        int n = s.length();
        std::vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    
    int shortestMatchingSubstring(std::string s, std::string p) {
        int n = s.size();
        int m = p.size();
        
        std::string prefix = "";
        std::string middle = "";
        std::string suffix = "";
        int pos = 0;
        while(pos < m && p[pos] != '*') {
            prefix.push_back(p[pos++]);
        }
        pos += 1;
        while(pos < m && p[pos] != '*') {
            middle.push_back(p[pos++]);
        }
        pos += 1;
        while(pos < m && p[pos] != '*') {
            suffix.push_back(p[pos++]);
        }
        
        if(prefix.empty() && suffix.empty() && middle.empty()) {
            return 0;
        }
        
        std::vector<int> a;
        std::vector<int> b;
        std::vector<int> c;
        if(!prefix.empty()) {
            std::string t = prefix + "#" + s;
            std::vector<int> pf = prefix_function(t);
            for(int i = prefix.size() + 1; i < t.size(); i++) {
                if(pf[i] >= prefix.size()) {
                    a.push_back(i - prefix.size() + 1 - prefix.size() - 1);
                }
            }
        }
        if(!middle.empty()) {
            std::string t = middle + "#" + s;
            std::vector<int> pf = prefix_function(t);
            for(int i = middle.size() + 1; i < t.size(); i++) {
                if(pf[i] >= middle.size()) {
                    b.push_back(i - middle.size() + 1 - middle.size() - 1);
                }
            }
        }
        if(!suffix.empty()) {
            std::string t = suffix + "#" + s;
            std::vector<int> pf = prefix_function(t);
            for(int i = suffix.size() + 1; i < t.size(); i++) {
                if(pf[i] >= suffix.size()) {
                    c.push_back(i - suffix.size() + 1 - suffix.size() - 1);
                }
            }
        }
        
        int ans = INF;
        
        if(!a.empty() && !b.empty() && !c.empty()) {
            for(int now : a) {
                int l = now;
                int r = now + prefix.size();
                
                auto it = std::lower_bound(b.begin(), b.end(), r);
                if(it == b.end()) {
                    continue;
                }
                r = *it + middle.size();
                
                it = std::lower_bound(c.begin(), c.end(), r);
                if(it == c.end()) {
                    continue;
                }
                r = *it + suffix.size();
                ans = std::min(ans, r - l);
            }
        } 
        
        if(!a.empty() && !c.empty() && b.empty() && middle.empty()) {
            for(int now : a) {
                int l = now;
                int r = now + prefix.size();
                auto it = std::lower_bound(c.begin(), c.end(), r);
                if(it == c.end()) {
                    continue;
                }
                r = *it + suffix.size();
                ans = std::min(ans, r - l);
            }
        }
        
        if(!a.empty() && !b.empty() && c.empty() && suffix.empty()) {
            for(int now : a) {
                int l = now;
                int r = now + prefix.size();
                auto it = std::lower_bound(b.begin(), b.end(), r);
                if(it == b.end()) {
                    continue;
                }
                r = *it + middle.size();
                ans = std::min(ans, r - l);
            }
        }
        
        if(!a.empty() && b.empty() && c.empty() && middle.empty() && suffix.empty()) {
            ans = prefix.size();
        }
        
        if(a.empty() && prefix.empty() && !b.empty() && !c.empty()) {
            for(int now : b) {
                int l = now;
                int r = now + middle.size();
                auto it = std::lower_bound(c.begin(), c.end(), r);
                if(it == c.end()) {
                    continue;
                }
                r = *it + suffix.size();
                ans = std::min(ans, r - l);
            }
        }
        
        if(a.empty() && prefix.empty() && !b.empty() && c.empty() && suffix.empty()) {
            ans = middle.size();
        }
        
        if(a.empty() && prefix.empty() && b.empty() && middle.empty() && !c.empty()) {
            ans = suffix.size();
        }
        
        return ans == INF ? -1 : ans;
    }
};
