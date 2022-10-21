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

    vector<pair<LL, LL>> A(N, {0, 0});

    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i].second;
    }

    if(N == 1) {
        cout << A[0].first << '\n';
        return;
    }

    LL ans = 0LL;
    for(int l = 0, r = N - 1; l <= r; ) {
        if(l == r) {
            ans += A[l++].first;
        } else {
            if(A[l].second <= A[r].second) {
                ans += A[l].first;
                A[l + 1].first += A[l].second;
                l++;
            } else {
                ans += A[r].first;
                A[r - 1].first += A[r].second;
                r--;
            }
        }
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
