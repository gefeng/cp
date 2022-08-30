#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>
#include <string>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<string> G(N);
    for(int i = 0; i < N; i++) {
        cin >> G[i];
    }

    auto valid = [&](const int& r, const int& c) {
        return r >= 0 && c >= 0 && r < N && c < M; 
    };

    array<int, 8> dr{-1, 0, 1, 0, 1, 1, -1, -1};
    array<int, 8> dc{0, 1, 0, -1, 1, -1, 1, -1};
    //bool has = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(G[i][j] == '*') {
                int cnt_adj = 0;
                int cnt_dia = 0;
                for(int k = 0; k < 8; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if(valid(ni, nj) && G[ni][nj] == '*') {
                        if(k < 4) {
                            cnt_adj++;
                        } else {
                            cnt_dia++;
                        }
                    }
                }

                if(cnt_adj == 1 && cnt_dia == 1) {
                    for(int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if(valid(ni, nj) && G[ni][nj] == '*') {
                            int kk = 0;
                            if(k == 0 || k == 2) {
                                kk = 1; 
                            }

                            int cnt = 0;
                            for(; kk < 4; kk += 2) {
                                int ni_1 = ni + dr[kk];
                                int nj_1 = nj + dc[kk];
                                if(valid(ni_1, nj_1) && G[ni_1][nj_1] == '*') {
                                    cnt++;
                                }
                            }

                            if(cnt == 0) {
                                cout << "NO" << '\n';
                                return;
                            }
                        }
                    }
                } else if(cnt_adj == 2 && cnt_dia == 0) {
                    for(int k = 0; k < 2; k++) {
                        int ni_1 = i + dr[k];
                        int nj_1 = j + dc[k];
                        int ni_2 = i + dr[k + 2];
                        int nj_2 = j + dc[k + 2];
                        if(valid(ni_1, nj_1) && valid(ni_2, nj_2) && G[ni_1][nj_1] == '*' && G[ni_2][nj_2] == '*') {
                            cout << "NO" << '\n';    
                            return;
                        }
                    }
                } else {
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
    }

    cout << "YES" << '\n';
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
