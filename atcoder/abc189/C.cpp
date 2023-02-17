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

    vector<int> dp_l(N, -1);
    vector<int> dp_r(N, N);
    vector<int> s;
    for(int i = 0; i < N; i++) {
        while(!s.empty() && A[s.back()] >= A[i]) {
            s.pop_back();
        }

        if(!s.empty()) {
            dp_l[i] = s.back();
        }

        s.push_back(i);
    }

    s = vector<int>();
    for(int i = N -1 ; i >= 0; i--) {
        while(!s.empty() && A[s.back()] >= A[i]) {
            s.pop_back();
        }

        if(!s.empty()) {
            dp_r[i] = s.back();
        }

        s.push_back(i);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int l = dp_l[i] + 1;
        int r = dp_r[i] - 1;
        ans = max(ans, A[i] * (r - l - 1));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
