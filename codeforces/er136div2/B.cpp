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

    vector<int> D(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> D[i];
    }

    vector<int> ans(N, 0);
    ans[0] = D[0];

    for(int i = 1; i < N; i++) {
        if(D[i] && ans[i - 1] - D[i] >= 0) {
            cout << -1 << '\n';
            return;
        }
        ans[i] = ans[i - 1] + D[i];
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
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
