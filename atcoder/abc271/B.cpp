#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> S(N);
    for(int i = 0; i < N; i++) {
        int L;
        cin >> L;
        S[i].reserve(L);
        for(int j = 0; j < L; j++) {
            int X;
            cin >> X;
            S[i].push_back(X);
        }
    }

    vector<int> ans(Q, 0);
    for(int i = 0; i < Q; i++) {
        int X, Y;
        cin >> X >> Y;
        X--;
        Y--;
        ans[i] = S[X][Y];
    }

    for(int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
