#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> events(2 * n);
        
        for(int i = 0; i < n; i++) {
            events[i] = {intervals[i][0], 1};
            events[i + n] = {intervals[i][1] + 1, -1};
        }

        sort(events.begin(), events.end());

        int sum = 0;
        int ans = 0;
        for(auto& e : events) {
            sum += e.second;
            ans = max(ans, sum);
        }

        return ans;
    }
};
