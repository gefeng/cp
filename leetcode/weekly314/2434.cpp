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
    string robotWithString(string s) {
        int n = s.length();
        string ans = "";
        string t = "";
        
        vector<vector<int>> pos(26);
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            pos[c].push_back(i);
        }
        
        int cur_pos = 0;
        for(int c = 0; c < 26; c++) {
            while(!t.empty() && t.back() - 'a' <= c) {
                ans.push_back(t.back());
                t.pop_back();
            }
            vector<int>& p = pos[c];
            if(!p.empty()) {
                auto it = lower_bound(p.begin(), p.end(), cur_pos);
                if(it != p.end()) {
                    int to = p.back();
                    while(cur_pos <= to) {
                        if(s[cur_pos] - 'a' == c) {
                            ans.push_back((char)(c + 'a'));
                        } else {
                            t.push_back((char)(s[cur_pos]));
                        }
                        cur_pos++;
                    }
                    if(cur_pos == n) break;
                }
            }
            
            
        }
        
        for(int i = t.length() - 1; i >= 0; i--) {
            ans.push_back(t[i]);
        }
        
        return ans;
    }
};
