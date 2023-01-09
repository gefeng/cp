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
    int countDigits(int num) {
        int ans = 0;
        int x = num;
        
        while(x) {
            int d = x % 10;
            if(num % d == 0) {
                ans += 1;
            }
            x /= 10;
        }
        
        return ans;
    }
};
