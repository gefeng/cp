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

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        if(T == 1) {
            int K, X;
            cin >> K >> X;
            K -= 1;
            A[K] = X;
        } else {
            int K;
            cin >> K;
            K -= 1;
            cout << A[K] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
