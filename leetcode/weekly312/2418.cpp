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
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, int>> s(n, {0, 0});
        
        for(int i = 0; i < n; i++) {
            s[i].first = heights[i];
            s[i].second = i;
        }
        
        sort(s.begin(), s.end());
        
        vector<string> ans;
        ans.reserve(n);
        for(int i = n - 1; i >= 0; i--) {
            ans.push_back(names[s[i].second]);
        }
        
        return ans;
    }
};
