#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(K, 0);
    for(int i = 0; i < K; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < Q; i++) {
        int X;
        cin >> X;

        X--;
        if(A[X] < N - 1 && (X == K - 1 || A[X + 1] - A[X] > 1)) {
            A[X] += 1;
        }
    }

    for(int i = 0; i < K; i++) {
        cout << A[i] + 1 << " \n"[i == K - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
