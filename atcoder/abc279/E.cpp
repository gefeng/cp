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

    vector<int> A(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    vector<int> pos_one(M);
    for(int i = 0, p = 0; i < M; i++) {
        pos_one[i] = p;
        if(A[i] == p) {
            p += 1;
        } else if(A[i] + 1 == p) {
            p -= 1;
        }
    }

    vector<int> pos(N);
    for(int i = 0; i < N; i++) {
        pos[i] = i;
    }

    vector<int> ans(M);
    for(int i = M - 1; i >= 0; i--) {
        ans[i] = pos[pos_one[i]];
        swap(pos[A[i]], pos[A[i] + 1]);
    }

    for(int i = 0; i < M; i++) {
        cout << ans[i] + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
