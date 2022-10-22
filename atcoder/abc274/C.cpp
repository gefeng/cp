#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<int> d(2 * N + 1, 0);
    for(int i = 0; i < N; i++) {
        int j = A[i];
        d[i * 2 + 1] = d[j] + 1;
        d[i * 2 + 2] = d[j] + 1;
    }

    for(int i = 0; i < 2 * N + 1; i++) {
        cout << d[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
