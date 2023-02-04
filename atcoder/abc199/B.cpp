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

    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int l = 0;
    int r = 1000;
    for(int i = 0; i < N; i++) {
        l = max(l, A[i]);
        r = min(r, B[i]);
    }

    cout << max(0, r - l + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
