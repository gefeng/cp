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
    int smallestNumber(int n, int t) {
        int ans = n;
        while(true) {
            int x = ans;
            int p = 1;
            while(x) {
                p *= x % 10;
                x /= 10;
            }
            if(p % t == 0) {
                break;
            }
            ans += 1;
        }
        return ans;
    }
};
