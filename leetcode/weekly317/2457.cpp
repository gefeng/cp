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
using LL = long long;

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        LL sum = 0LL;
        LL x = n;
        while(x) {
            sum += x % 10LL;
            x /= 10LL;
        }
        
        x = n;
        LL ans = 0LL;
        LL carry = 0LL;
        LL base = 1LL;
        while(x && sum + carry > target) {
            LL d = x % 10LL;
            sum -= d;
            d += carry;
            d %= 10LL;
            
            if(d > 0LL) {
                ans += base * (10LL - d); 
                carry = 1LL;
            } 
            
            base *= 10LL;
            x /= 10LL;
        }
        
        return ans;
    }
};
