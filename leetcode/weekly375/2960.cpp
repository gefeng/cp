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
    int countTestedDevices(std::vector<int>& batteryPercentages) {
        int ans = 0;
        int n = batteryPercentages.size();
        
        for(int i = 0; i < n; i++) {
            if(batteryPercentages[i] > 0) {
                ans += 1;
                for(int j = i + 1; j < n; j++) {
                    batteryPercentages[j] = std::max(0, batteryPercentages[j] - 1);
                }
            }
        }
        return ans;
    }
};
