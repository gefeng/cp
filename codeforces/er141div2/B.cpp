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

    vector<vector<int>> ans(N, vector<int>(N, 0));
    int flag = 0;
    for(int i = 0, l = 1, r = N * N; i < N; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < N; j++) {
                if(flag == 0) {
                    ans[i][j] = r;
                    r -= 1;
                } else {
                    ans[i][j] = l;
                    l += 1;
                }
                flag ^= 1;
            }
        } else {
            for(int j = N - 1; j >= 0; j--) {
                if(flag == 0) {
                    ans[i][j] = r;
                    r -= 1;
                } else {
                    ans[i][j] = l;
                    l += 1;
                }
                flag ^= 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << ans[i][j] << " \n"[j == N - 1];
        }
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
