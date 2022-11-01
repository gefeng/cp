#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const array<int, 8> DR{0, 1, 0, -1, 1, -1, 1, -1};
const array<int, 8> DC{1, 0, -1, 0, 1, -1, -1, 1};

void run_case() {
    int N;
    cin >> N;

    vector<vector<int>> G(N, vector<int>(N, 0));
    
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for(int j = 0; j < N; j++) {
            G[i][j] = S[j] - '0'; 
        }
    }

    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int d = 0; d < 8; d++) {
                int r = i;
                int c = j;
                LL x = 0LL;
                for(int k = 0; k < N; k++) {
                    x = x * 10LL + G[r][c];
                    r = (r + DR[d] + N) % N;
                    c = (c + DC[d] + N) % N;
                }
                ans = max(ans, x);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
