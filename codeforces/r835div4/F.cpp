#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;
    
    LL C, D;
    cin >> C >> D;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), greater<int>());

    LL sum = 0LL;
    for(int i = 0; i < min(N, (int)D); i++) {
        sum += A[i];
    }

    if(sum >= C) {
        cout << "Infinity" << '\n';
        return;
    }

    LL lo = 0LL;
    LL hi = D - 1LL;
    LL ans = -1;
    while(lo <= hi) {
        LL mid = (lo + hi) / 2LL;

        LL s = min((LL)N, mid + 1LL);
        LL t = D / (mid + 1LL);
        LL r = D % (mid + 1LL);
        LL x = 0LL;

        for(int i = 0; i < (int)s; i++) {
            x += A[i]; 
        }

        x *= t;
        
        for(int i = 0; i < min(N, (int)r); i++) {
            x += A[i];
        }

        if(x >= C) {
            ans = mid;
            lo = mid + 1LL;
        } else {
            hi = mid - 1LL;
        }
    }

    if(ans == -1LL) {
        cout << "Impossible" << '\n';
    } else {
        cout << ans << '\n';
    }
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
