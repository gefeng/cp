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
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        
        auto cmp = [&](const auto& r1, const auto& r2) {
            return r1[k] > r2[k];  
        };
        
        sort(score.begin(), score.end(), cmp);
        
        return score;
    }
};
