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
    int gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }

    bool isReachable(int targetX, int targetY) {
        while(targetX % 2 == 0) {
            targetX /= 2;
        }
        while(targetY % 2 == 0)  {
            targetY /= 2;
        }
        
        return gcd(targetX, targetY) == 1;
    }
};
