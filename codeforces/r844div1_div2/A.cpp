#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int INF = (int)2e9;

int dist(int a, int b, int x, int y) {
    return abs(a - x) + abs(b - y);
}

void run_case() {
    int W, D, H;
    cin >> W >> D >> H;

    int A, B, F, G;
    cin >> A >> B >> F >> G;

    int ans = INF;
    ans = min(B + dist(A, 0, F, G), D - B + dist(A, D, F, G));
    ans = min(ans, A + dist(0, B, F, G));
    ans = min(ans, W - A + dist(W, B, F, G));

    cout << ans + H << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
