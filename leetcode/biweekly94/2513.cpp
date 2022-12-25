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
    LL gcd(LL a, LL b) {
        if(a == 0LL) {
            return b;
        }    
        return gcd(b % a, a);
    }
    
    LL lcm(LL a, LL b) {
        return a * b / gcd(a, b);
    }
    
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        LL lo = 1;
        LL hi = 2e9;
        LL ans = 0;
        
        while(lo <= hi) {
            int mid = (lo + hi) >> 1LL;
            
            LL cnt1 = mid - mid / lcm(divisor1, divisor2);
            LL cnt2 = mid - mid / divisor1;
            LL cnt3 = mid - mid / divisor2;
    
            if(cnt1 >= uniqueCnt1 + uniqueCnt2 && cnt2 >= uniqueCnt1 && cnt3 >= uniqueCnt2) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
