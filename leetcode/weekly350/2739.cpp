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
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        int x = mainTank;
        int y = additionalTank;
        
        while(true) {
            if(x < 5) {
                ans += x * 10;
                break;
            }    
            
            ans += 50;
            x -= 5;
            
            if(y) {
                x += 1;
                y -= 1;
            }
        }
        
        return ans;
    }
};
