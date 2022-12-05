#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S;
    int K;
    cin >> S >> K;

    int n = S.length();
    int lo = 0;
    int hi = n;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        bool is_ok = false;
        int cnt = 0;
        for(int l = 0, r = 0; r < n; r++) {
            cnt += S[r] == '.' ? 1 : 0;

            if(r - l + 1 > mid) {
                cnt -= S[l++] == '.' ? 1 : 0;
            }
            
            if(r - l + 1 == mid && cnt <= K) {
                is_ok = true;
                break;
            }
        }

        if(is_ok) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
