#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> B(N);
    for(int i = 0; i < N; i++) {
        B[i] = {A[i], i};
    }

    sort(B.begin(), B.end());

    int lo = 1;
    int hi = N;
    int ans = N + 1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        int t = N - mid + 1;

        int cnt = 0;
        int x = M;
        bool ok = false;
        for(int i = 0; i < N; i++) {
            if(B[i].first <= x) {
                x -= B[i].first;
                cnt += 1; 
            }
        }

        if(cnt >= t) {
            ok = true;
        } else {
            x = M;
            cnt = 0;
            if(x >= A[t - 1]) {
                x -= A[t - 1];
                cnt = 1;
                for(int i = 0; i < N; i++) {
                    if(B[i].second == t - 1) continue;
                    if(x >= B[i].first) {
                        x -= B[i].first;
                        cnt += 1;
                    }
                }

                if(cnt >= t - 1) {
                    ok = true;
                }
            }
        }

        if(ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
