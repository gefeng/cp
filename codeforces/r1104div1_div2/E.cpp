#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i]--;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        if(B[i] != -1) {
            B[i]--;
        }
    }

    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(!vis[i] && B[i] != -1) {
            int now = i;
            while(!vis[now]) {
                vis[now] = 1;
                if(B[A[now]] == -1) {
                    B[A[now]] = A[B[now]];
                } else {
                    if(B[A[now]] != A[B[now]]) {
                        std::cout << "NO" << '\n';
                        return;
                    }
                }
                now = A[now];
            }
        }
    }

    std::vector<int> seen(N, 0);
    for(int i = 0; i < N; i++) {
        if(B[i] != -1) {
            if(seen[B[i]]) {
                std::cout << "NO" << '\n';
                return;
            }
            seen[B[i]] = 1;
        }
    }

    std::vector<std::vector<int>> c1(N + 1);
    std::vector<std::vector<int>> c2(N + 1);
    vis.assign(N, 0);
    for(int i = 0; i < N; i++) {
        if(B[i] == -1 && !vis[i]) {
            int now = i;
            int len = 0;
            while(!vis[now]) {
                vis[now] = 1;
                now = A[now];
                len++;
            }
            c1[len].push_back(i);
        }
    }    

    vis.assign(N, 0);
    for(int i = 0; i < N; i++) {
        if(!seen[i] && !vis[i]) {
            int now = i;
            int len = 0;
            while(!vis[now]) {
                vis[now] = 1;
                now = A[now];
                len++;
            }
            c2[len].push_back(i);
        }
    }

    for(int len =  1; len <= N; len++) {
        int m = c1[len].size();
        for(int i = 0; i < m; i++) {
            int now = c1[len][i];
            int val = c2[len][i];
            while(B[now] == -1) {
                B[now] = val;
                now = A[now];
                val = A[val];
            }
        }
    }

    std::cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << B[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
