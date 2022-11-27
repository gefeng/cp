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
    int pivotInteger(int n) {
        for(int i = 1; i <= n; i++) {
            int l = 0;
            int r = 0;
            for(int j = 1; j <= i; j++) {
                l += j;
            }
            for(int j = i; j <= n; j++) {
                r += j;
            }
            if(l == r) {
                return i;
            }
        }
        
        return -1;
    }
};
