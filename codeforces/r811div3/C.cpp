#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int S;
    cin >> S;

    LL ans = 0;
    LL base = 1;
    for(int i = 9; i >= 1; i--) {
        if(S - i >= 0) {
            S -= i;
            ans += base * i;
            base *= 10;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
