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

    vector<int> ans(N);
    int sum = 0;
    for(int i = 1; i < N; i++) {
        sum ^= A[i];
    }

    ans[0] = sum;

    for(int i = 0; i < N - 1; i++) {
        ans[i + 1] = ans[i] ^ A[i] ^ A[i + 1];
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
