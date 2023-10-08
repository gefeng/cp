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
    int minProcessingTime(std::vector<int>& processorTime, std::vector<int>& tasks) {
        int ans = 0;
        int n = processorTime.size();
        
        std::sort(tasks.begin(), tasks.end(), std::greater<int>());
        std::sort(processorTime.begin(), processorTime.end());
        
        for(int i = 0, j = 0; i < n; i++, j += 4) {
            for(int k = 0; k < 4; k++) {
                ans = std::max(ans, processorTime[i] + tasks[j + k]);
            }
        }
        
        return ans;
    }
};
