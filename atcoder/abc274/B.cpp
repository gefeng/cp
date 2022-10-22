#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<string> G(N, "");
    for(int i = 0; i < N; i++) {
        cin >> G[i];
    }

    for(int c = 0; c < M; c++) {
        int cnt = 0;
        for(int r = 0; r < N; r++) {
            if(G[r][c] == '#') {
                cnt++;
            }
        }

        cout << cnt << " \n"[c == M - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
