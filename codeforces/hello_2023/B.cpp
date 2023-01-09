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

    if(N == 3) {
        cout << "NO" << '\n';
        return;
    }

    vector<int> ans(N);
    if(N % 2 == 0) {
        for(int i = 0; i < N; i++) {
            if(i % 2 == 0) {
                ans[i] = 1;
            } else {
                ans[i] = -1;
            }
        }
    } else {
        int x = (N - 1) / 2;
        int y = (N - 3) / 2;
        for(int i = 0; i < N; i++) {
            if(i % 2 == 0) {
                ans[i] = y;
            } else {
                ans[i] = -x;
            }
        }
    }

    cout << "YES" << '\n';
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
