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

    vector<array<int, 3>> A(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            array<int, 3> x = A[i];
            array<int, 3> y = A[j];

            if(x[1] > y[1]) {
                swap(x, y);
            }

            if(y[1] < x[2] || (y[1] == x[2] && x[0] % 2 == 1 && y[0] < 3)) {
                ans += 1;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
