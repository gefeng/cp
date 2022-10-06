#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using LL = long long;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }

    return res;
}

void run_case() {
    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        LL K;
        cin >> K;

        LL len = 1LL;
        LL cnt = 9LL;
        
        while(K > cnt * len) {
            K -= cnt * len;
            len++;
            cnt *= 10LL;
        }

        LL pos = (K + len - 1LL) / len;
        LL num = q_pow(10LL, len - 1LL) + pos - 1LL;
        LL rem = K % len;
        rem = rem == 0 ? 1LL : len - rem + 1LL;

        LL ans = 0LL;
        while(rem) {
            ans = num % 10LL; 
            num /= 10LL;
            rem--;
        }

        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
