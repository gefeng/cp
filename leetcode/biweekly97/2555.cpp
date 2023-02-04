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
    int maximizeWin(vector<int>& prizePositions, int k) {     
        int n = prizePositions.size();
        
        vector<pair<int, int>> range;
        
        for(int i = 0; i < n; i++) {
            auto it = upper_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] + k);
            range.emplace_back(i, it - prizePositions.begin() - 1);
        }
        
        int max_v = 0;
        int ans = 0;
        int l = 0;
        for(int r = 0; r < n; r++) {
            while(range[l].second < range[r].first) {
                max_v = max(max_v, range[l].second - range[l].first + 1);
                l += 1;
            }
            
            ans = max(ans, max_v + range[r].second - range[r].first + 1);
        }
        
        ans = max(ans, range[n - 1].second - range[l].first + 1);
        
        return ans;
    }
};
