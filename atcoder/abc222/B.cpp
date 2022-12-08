#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, P;
    cin >> N >> P;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;

        ans += X < P ? 1 : 0;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
