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
    int hardestWork(int n, vector<vector<int>>& logs) {
        int max_v = logs[0][1];
        int max_w = logs[0][0];
        int m = logs.size();
        for(int i = 1; i < m; i++) {
            int t = logs[i][1] - logs[i - 1][1];
            if(t > max_v || (t == max_v && logs[i][0] < max_w)) {
                max_w = logs[i][0];
                max_v = t;
            }
        }
        
        return max_w;
    }
};
