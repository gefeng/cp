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
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 == num2) {
            return -1;
        }

        for(int i = 0; i <= 60; i++) {
            LL x = num1 - 1LL * i * num2;
            
            if(x > 0 && __builtin_popcountll(x) <= i && x >= i) {
                return i;
            }
        }
        
        return -1;
    }
};
