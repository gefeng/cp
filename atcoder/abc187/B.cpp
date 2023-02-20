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

    vector<int> X(N);
    vector<int> Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int x1 = X[i];
            int y1 = Y[i];
            int x2 = X[j];
            int y2 = Y[j];

            int dx = x1 - x2;
            int dy = y1 - y2;
            
            if(x1 - x2 < 0) {
                ans += dy <= -dx && dy >= dx ? 1 : 0;
            } else {
                ans += dy >= -dx && dy <= dx ? 1 : 0;
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
