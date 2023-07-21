#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

void run_case() {
    int N, M, SX, SY, D;
    cin >> N >> M >> SX >> SY >> D;
    
    int d_top = SX - 1;
    int d_bottom = N - SX;
    int d_left = SY - 1;
    int d_right = M - SY;

    int ans = -1;
    if((d_top > D && d_right > D) || (d_bottom > D && d_left > D)) {
        ans = N + M - 2; 
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
