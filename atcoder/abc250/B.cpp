#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<vector<char>> ans(A * N, vector<char>(N * B, '.'));
    for(int i = 0; i < A * N; i++) {
        int st = (i / A) % 2 == 0 ? B : 0;
        for(int j = st; j < N * B; j += 2 * B) {
            for(int k = 0; k < B; k++) {
                ans[i][j + k] = '#';
            }
        }
    }

    for(int i = 0; i < A * N; i++) {
        for(int j = 0; j < N * B; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
