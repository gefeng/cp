#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;
const double INF = 1e13;

vector<array<int, 3>> T;

double get_dist(double x_1, double y_1, double x_2, double y_2) {
    return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}

void run_case() {
    int N, M;
    cin >> N >> M;

    T.clear();
    T.resize(N + M, {0});

    for(int i = 0; i < N; i++) {
        cin >> T[i][0] >> T[i][1];
        T[i][2] = 0;
    }

    for(int i = 0; i < M; i++) {
        cin >> T[i + N][0] >> T[i + N][1];
        T[i + N][2] = 1;
    }

    vector<vector<double>> dp(N + M, vector<double>(1 << (M + N), INF));
    for(int i = 0; i < M + N; i++) {
        dp[i][1 << i] = get_dist(T[i][0], T[i][1], 0, 0); 
    }

    for(int i = 1; i < (1 << (M + N)); i++) {
        for(int j = 0; j < N + M; j++) {
            if(i & (1 << j)) {
                int pre_m = i ^ (1 << j);
                int speed = 1;
                for(int k = 0; k < M + N; k++) {
                    if((pre_m & (1 << k)) && T[k][2]) {
                        speed *= 2; 
                    }
                }

                for(int k = 0; k < M + N; k++) {
                    if((pre_m & (1 << k)) && (dp[k][pre_m] < INF - EPS || dp[k][pre_m] > INF + EPS)) {
                        dp[j][i] = min(dp[j][i], dp[k][pre_m] + get_dist(T[j][0], T[j][1], T[k][0], T[k][1]) / (double)speed); 
                    }
                } 
            }
        } 
    }

    double ans = INF;
    for(int i = 1; i < (1 << (M + N)); i++) {
        int speed = 1;
        int visit = 0;
        for(int j = 0; j < M + N; j++) {
            if(i & (1 << j)) {
                if(T[j][2]) {
                    speed *= 2;
                } else {
                    visit += 1;
                }
            }
        }

        if(visit == N) {
            for(int j = 0; j < M + N; j++) {
                if((dp[j][i] < INF - EPS || dp[j][i] > INF + EPS)) {
                    ans = min(ans, dp[j][i] + get_dist(T[j][0], T[j][1], 0, 0) / (double)speed);
                }
            }
        }
    }

    cout << setprecision(20) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
