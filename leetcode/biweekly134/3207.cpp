#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    long long maximumPoints(std::vector<int>& enemyEnergies, int currentEnergy) {
        int n = enemyEnergies.size();
        int64_t ans = 0;
        int64_t cur = currentEnergy;
        
        std::sort(enemyEnergies.begin(), enemyEnergies.end());
        
        if(currentEnergy < enemyEnergies[0]) {
            return ans;
        }
        
        cur -= enemyEnergies[0];
        for(int x : enemyEnergies) {
            cur += x;
        }
        
        for(int i = 0; i < n; i++) {
            ans = std::max(ans, cur / enemyEnergies[i]);
        }
        
        return  ans;
    }
};
