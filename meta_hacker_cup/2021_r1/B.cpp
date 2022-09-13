#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case(int T) {
    int N, M, A, B;
    cin >> N >> M >> A >> B;

    vector<vector<int>> ans(N, vector<int>(M, 1000));
    bool ok = true;
    if(M + N - 1 > A || M + N - 1 > B) {
        ok = false;
    } else {
        int len = M + N - 1;

        if(M * N > 4) {
            int path_a_st = (A - len + 2) / 2;
            int path_a_ed = path_a_st + ((A - len + 2) % 2);
            int path_b_st = (B - len + 2) / 2;
            int path_b_ed = path_b_st + ((B - len + 2) % 2);

            ans[0][0] = path_a_st;
            ans[N - 1][M - 1] = path_a_ed;
            ans[0][M - 1] = path_b_st;
            ans[N - 1][0] = path_b_ed;

            if(M > 2) {
               for(int i = 1; i < M - 1; i++) {
                   ans[0][i] = 1;
               } 
               for(int i = 1; i < N; i++) {
                   ans[i][1] = 1;
                   ans[i][M - 2] = 1;
               }
            } else {
                for(int i = 1; i < N - 1; i++) {
                    ans[i][0] = 1;
                }
                ans[1][1] = 1;
                ans[N - 2][1] = 1;
            }
        } else {
            ans[0][0] = 1;
            ans[1][0] = 1;
            ans[0][1] = B - 2;
            ans[1][1] = A - 2;
        }
    }

    if(ok) {
        cout << "Case #" << T << ": Possible" << '\n';
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cout << ans[i][j] << " \n"[j == M - 1];
            }
        }
    } else {
        cout << "Case #" << T << ": Impossible" << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
