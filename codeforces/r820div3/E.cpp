#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL query(LL a, LL b) {
    cout << "? " << a << ' ' << b << endl;
    LL Q; cin >> Q;
    return Q;
}
void run_case() {
    LL ans = 0;
    for(int i = 2; i < 27; i++) {
        LL res_1 = query(1, i);
        LL res_2 = query(i, 1);
        
        if(res_1 == -1LL) {
            ans = i - 1;
            break;
        }

        if(res_1 != res_2) {
            ans = res_1 + res_2;
            break;
        }
    }
    cout << "! " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
