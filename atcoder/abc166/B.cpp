#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<bool> has(N, false);
    for(int i = 0; i < K; i++) {
        int D;
        cin >> D;

        for(int j = 0; j < D; j++) {
            int S;
            cin >> S;

            S -= 1;
            has[S] = true;
        }
    } 

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(!has[i]) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
