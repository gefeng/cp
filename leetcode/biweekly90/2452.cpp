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
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string s : queries) {
            for(string t : dictionary) {
                int n = s.length();
                int cnt = 0;
                for(int i = 0; i < n; i++) {
                    if(s[i] != t[i]) {
                        cnt++;
                    }
                }
                
                if(cnt < 3) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        
        return ans;
    }
};
