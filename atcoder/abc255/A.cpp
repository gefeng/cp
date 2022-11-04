#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> A(2, vector<int>(2, 0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> A[i][j];
        }
    }

    cout << A[R - 1][C - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
