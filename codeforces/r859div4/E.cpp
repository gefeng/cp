#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    auto q = [](int l, int r) {
        int k = r - l + 1; 
        cout << "? " << k << ' ';
        for(int i = l; i <= r; i++) {
            cout << i + 1 << " \n"[i == r]; 
        }
        cout.flush();

        int res;
        cin >> res;
        return res;
    };

    int lo = 0; 
    int hi = N - 1;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        int res = q(lo, mid);
        if(res > psum[mid + 1] - psum[lo]) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << "! " << ans + 1 << endl;
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
