#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = P - 1, j = R - 1; i < Q; i += 1, j += 1) {
        swap(A[i], A[j]);
    }

    for(int i = 0; i < N; i++) {
        cout << A[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
