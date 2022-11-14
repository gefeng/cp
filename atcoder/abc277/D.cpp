#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if(N == 1) {
        cout << 0 << '\n';
        return;
    }

    sort(A.begin(), A.end());

    for(int i = 0; i < N; i++) {
        A.push_back(A[i]);
    } 

    vector<LL> psum(2 * N + 1, 0LL);
    for(int i = 1; i <= 2 * N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    LL max_s = 0LL;
    for(int i = 0; i < 2 * N; ) {
        int j = i;
        while(i < 2 * N && (i == j || A[i] == A[i - 1] || A[i] == (A[i - 1] + 1) % M)) {
            i++;
        }
        max_s = max(max_s, psum[i] - psum[j]);
        max_s = min(max_s, psum[N]); // 1 1 1 1
    } 

    cout << psum[N] - max_s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
