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
    std::vector<int> findPeaks(std::vector<int>& mountain) {
        std::vector<int> ans;
        int n = mountain.size();
        
        for(int i = 1; i < n - 1; i++) {
            if(mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
