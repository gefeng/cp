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

    vector<pair<int, int>> s;
    s.reserve(N);

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(!s.empty() && s.back().first == A[i]) {
            s.back().second += 1;
        } else {
            s.emplace_back(A[i], 1);
        }

        ans += 1;

        if(!s.empty() && s.back().first == s.back().second) {
            ans -= s.back().second;
            s.pop_back();
        }

        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
