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
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
    
        std::sort(capacity.begin(), capacity.end(), std::greater<int>());
        
        int sum = 0;
        for(int x : apple) {
            sum += x;
        }
        
        int ans = 0;
        for(int b : capacity) {
            if(sum) {
                sum = std::max(sum - b, 0);
                ans += 1;
            } else {
                break;
            }
        }
        
        return ans;
    }
};
