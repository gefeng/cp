#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

class Solution {
public:
    bool isFascinating(int n) {
        LL x = n;
        concate(x, 2 * n);
        concate(x, 3 * n);
        
        std::array<int, 10> cnt = {};
        while(x) {
            cnt[x % 10] += 1;
            x /= 10;
        }
        
        for(int i = 1; i < 10; i++) {
            if(cnt[i] != 1) {
                return false;
            }
        }
        
        return cnt[0] == 0;
    }
    
    void concate(LL& x, int t) {
        int y = t;
        while(y) {
            x *= 10;
            y /= 10;
        }
        
        x += t;
    }
};
