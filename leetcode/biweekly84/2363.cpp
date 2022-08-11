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
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> map;
        for(auto& x : items1) {
            map[x[0]] += x[1];
        }
        for(auto& x : items2) {
            map[x[0]] += x[1];
        }
        
        vector<vector<int>> ans;
        for(auto& it : map) {
            vector<int> v;
            v.push_back(it.first);
            v.push_back(it.second);
            ans.emplace_back(v);
        }
        
        sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        return ans;
    }
};
