#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int INF = (int)2e9;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> dp1(N, INF);        
    vector<int> dp2(N, INF);

    dp1[0] = 0;
    for(int i = 0; i < N - 1; i++) {
        string s = A[i];
        if(dp1[i] == INF) {
            continue;
        }

        for(int j = 0; j < M; j++) {
            if(s[j] == '1') {
                dp1[i + j + 1] = min(dp1[i + j + 1], dp1[i] + 1);
            }
        }
    }

    dp2[N - 1] = 0;
    for(int i = N - 2; i >= 0; i--) {
        string s = A[i];

        for(int j = 0; j < M; j++) {
            if(s[j] == '1') {
                if(dp2[i + j + 1] != INF) {
                    dp2[i] = min(dp2[i], dp2[i + j + 1] + 1);
                }
            }
        }
    }

    for(int k = 1; k < N - 1; k++) {
        int ans = INF; 

        for(int i = max(0, k - M); i <= k - 1; i++) {
            if(dp1[i] == INF) {
                continue;
            }

            for(int j = k + 1; j <= min(k + M, N - 1); j++) {
                if(j - i <= M && A[i][j - i - 1] == '1' && dp2[j] != INF) {
                    ans = min(ans, dp1[i] + dp2[j] + 1);
                }
            }
        }

        cout << (ans == INF ? -1 : ans) << " \n"[k == N - 2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
