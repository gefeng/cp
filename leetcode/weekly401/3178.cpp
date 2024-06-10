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
    int numberOfChild(int n, int k) {
        int p = 0;
        int d = 1;
        while(k) {
            if(p == n - 1) {
                d = -1;
            }
            if(p == 0) {
                d = 1;
            }
            p += d;
            k -= 1;
        }
        
        return p;
    }
};
