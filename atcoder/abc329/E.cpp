#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;

    std::queue<int> q;
    std::vector<int> vis(N, 0);
    for(int i = 0; i <= N - M; i++) {
        if(S.substr(i, M) == T) {
            q.push(i);
            vis[i] = 1;
        } 
    }

    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int i = 0; i < M; i++) {
            S[p + i] = '#';
        }

        for(int i = p - M + 1; i <= p + M - 1; i++) {
            if(i >= 0 && i + M <= N && !vis[i]) {
                bool ok = true;
                for(int j = 0; j < M; j++) {
                    if(S[i + j] != '#' && S[i + j] != T[j]) {
                        ok = false;
                        break;
                    }
                } 
                if(ok) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }

    std::cout << (S == std::string(N, '#') ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
