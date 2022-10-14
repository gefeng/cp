#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case(int T) {
    int R, C, K;
    cin >> R >> C >> K;

    vector<string> G(R);
    for(int i = 0; i < R; i++) {
        cin >> G[i];
    }

    int ans = 0;
    vector<pair<int, int>> row_k(C, {0, 0});
    for(int i = 0; i < C; i++) {
        ans += G[K - 1][i] == 'X' ? 1 : 0;
        row_k[i].first = G[K - 1][i] == 'X' ? 1 : 0;
    }
    
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < K; j++) {
            if(G[j][i] == '.') {
                row_k[i].second++;
            }
        }
    }

    for(int i = 1; i <= R; i++) {
        if(i + K - 1 < R) {
            for(int j = 0; j < C; j++) {
                if(G[i + K - 1][j] == 'X') {
                    if(row_k[j].second > 0) {
                        row_k[j].first = 1;
                        row_k[j].second--;
                    }
                } else {
                    if(row_k[j].second > 0) {
                        row_k[j].first = 0;
                    }
                }
            } 
        } else {
            for(int j = 0; j < C; j++) {
                if(row_k[j].first && row_k[j].second > 0) {
                    row_k[j].first = 0;
                    row_k[j].second--;
                } 
            }
        }

        int cnt = 0;
        for(int j = 0; j < C; j++) {
            cnt += row_k[j].first;
        }
        ans = min(ans, i + cnt);
    }

    row_k = vector<pair<int, int>>(C, {0, 0});

    for(int i = 0; i < C; i++) {
        row_k[i].first = G[K - 1][i] == 'X' ? 1 : 0;
    }

    for(int i = 0; i < C; i++) {
        for(int j = K - 1; j < R; j++) {
            if(G[j][i] == '.') {
                row_k[i].second++;
            }
        }
    }

    for(int i = 1; i <= R; i++) {
        if(K - 1 - i >= 0) {
            for(int j = 0; j < C; j++) {
                if(G[K - 1 - i][j] == 'X') {
                    if(row_k[j].second > 0) {
                        row_k[j].first = 1;
                        row_k[j].second--;
                    }
                } else {
                    if(row_k[j].second > 0) {
                        row_k[j].first = 0;
                    }
                }
            } 
        } else {
            for(int j = 0; j < C; j++) {
                if(row_k[j].first && row_k[j].second > 0) {
                    row_k[j].first = 0;
                    row_k[j].second--;
                } 
            }
        }

        int cnt = 0;
        for(int j = 0; j < C; j++) {
            cnt += row_k[j].first;
        }
        ans = min(ans, i + cnt);
    }

    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
