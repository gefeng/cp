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

    vector<int> ans(N, 0);
    
    for(int i = 0, j = (N + 1) / 2; i < N; i += 2, j--) {
        ans[i] = j;
    }

    for(int i = 1, j = N; i < N; i += 2, j--) {
        ans[i] = j;
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
