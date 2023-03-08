#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int lo = 1;
    int hi = (int)1e9;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        bool ok = true;
        int cnt = 0;
        for(int x : A) {
            int need = (x + mid - 1) / mid - 1;
            if(cnt + need > K) {
                ok = false;
                break;
            }

            cnt += need;
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
