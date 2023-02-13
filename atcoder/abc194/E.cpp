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

    int lo = 0;
    int hi = N;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        bool ok = false;
        int cnt = 0;
        vector<int> f(N, 0);
        for(int l = 0, r = 0; r < N; r++) {
            f[A[r]] += 1;
            if(f[A[r]] == 1 && A[r] <= mid) {
                cnt += 1;
            }

            while(r - l + 1 > M) {
                f[A[l]] -= 1;
                if(f[A[l]] == 0 && A[l] <= mid) {
                    cnt -= 1; 
                }
                l += 1;
            }

            if(r - l + 1 == M) {
                if(cnt <= mid) {
                    ok = true;
                    break;
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
    cin.tie(nullptr);

    run_case();
}
