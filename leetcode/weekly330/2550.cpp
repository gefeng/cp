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

const LL MOD = (LL)1e9 + 7;

class Solution {
public:
    LL q_pow(LL x, LL y) {
        LL res = 1LL;
        while(y) {
            if(y & 1LL) {
                res *= x;
                res %= MOD;
            }
            x *= x;
            x %= MOD;
            y >>= 1LL;
        }
        return res;
    }

    int monkeyMove(int n) {
        LL ans = q_pow(2LL, n);
        
        return (ans - 2LL + MOD) % MOD;
    }
};
