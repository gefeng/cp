#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int INF = 2e9;

void run_case() {
    int N;
    cin >> N;

    vector<int> X(N);
    vector<int> Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    int max_1 = -INF; // x + y
    int max_2 = -INF; // x - y
    int max_3 = -INF; // -x + y
    int max_4 = -INF; // -x - y

    int min_1 = INF;
    int min_2 = INF;
    int min_3 = INF;
    int min_4 = INF;

    for(int i = 0; i < N; i++) {
        max_1 = max(max_1, X[i] + Y[i]);
        max_2 = max(max_2, X[i] - Y[i]);
        max_3 = max(max_3, -X[i] + Y[i]);
        max_4 = max(max_4, -X[i] - Y[i]);

        min_1 = min(min_1, X[i] + Y[i]);
        min_2 = min(min_2, X[i] - Y[i]);
        min_3 = min(min_3, -X[i] + Y[i]);
        min_4 = min(min_4, -X[i] - Y[i]);
    }

    int ans = -INF;
    ans = max(ans, max_1 - min_1);
    ans = max(ans, max_2 - min_2);
    ans = max(ans, max_3 - min_3);
    ans = max(ans, max_4 - min_4);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
