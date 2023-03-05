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
    int passThePillow(int n, int time) {
        int ans = 1;
        int d = -1;
        while(time) {
            if(ans == n || ans == 1) {
                d *= -1;
            }
            ans += d;
            time -= 1;
        }
        
        return ans;
    }
};
