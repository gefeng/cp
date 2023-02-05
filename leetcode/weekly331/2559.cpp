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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pos;
        string vowel = "aeiou";
        
        int n = words.size();
        for(int i = 0; i < n; i++) {
            string s = words[i];
            if(vowel.find(s[0]) != string::npos && vowel.find(s[s.size() - 1]) != string::npos) {
                pos.push_back(i);
            }
        }
        
        int m = queries.size();
        vector<int> ans(m, 0);
        
        for(int i = 0; i < m; i++) {
            auto l = lower_bound(pos.begin(), pos.end(), queries[i][0]);
            auto r = upper_bound(pos.begin(), pos.end(), queries[i][1]);
            
            ans[i] = r - l;
        }
        
        return ans;
    }
};
