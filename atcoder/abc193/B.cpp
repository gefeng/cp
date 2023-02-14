#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int INF = 2e9;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N), P(N), X(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> X[i];
    }

    int ans = INF;
    for(int i = 0; i < N; i++) {
        if(A[i] < X[i]) {
            ans = min(ans, P[i]);
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
