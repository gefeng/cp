#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M, T;
    cin >> N >> M >> T;

    vector<int> A(M);
    vector<int> B(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i] >> B[i]; 
    }

    int pre = 0;
    int cur = N;
    bool ans = true;
    for(int i = 0; i < M; i++) {
        int d = A[i] - pre;
        if(d >= cur) {
            ans = false;
            break;
        }

        cur -= d;

        cur = min(cur + B[i] - A[i], N);
        pre = B[i];
    }

    if(T - pre >= cur) {
        ans = false;
    }

    cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
