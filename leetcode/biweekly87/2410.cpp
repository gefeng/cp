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
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int m = players.size();
        int n = trainers.size();
        for(int l = 0, r = 0; l < m && r < n; ) {
            if(players[l] > trainers[r]) {
                r++;
            } else {
                ans++;
                l++;
                r++;
            }
        }
        
        return ans;
    }
};
