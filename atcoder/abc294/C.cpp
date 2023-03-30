#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<int> ans_a(N, 0);
    vector<int> ans_b(M, 0);
    for(int i = 0, j = 0, k = 0; i < N || j < M; k++) {
        if(i == N) {
            ans_b[j++] = k;
        } else if(j == M) {
            ans_a[i++] = k;
        } else {
            if(A[i] < B[j]) {
                ans_a[i++] = k;
            } else {
                ans_b[j++] = k;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << ans_a[i] + 1 << " \n"[i == N - 1];
    }

    for(int i = 0; i < M; i++) {
        cout << ans_b[i] + 1 << " \n"[i == M - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
