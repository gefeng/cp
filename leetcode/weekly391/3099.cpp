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
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int ans = 0;
        int n = x;
        while(x) {
            ans += x % 10;
            x /= 10;
        }
        
        return (n % ans == 0 ? ans : -1);
    }
};
