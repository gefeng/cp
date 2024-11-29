#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(A[i][j] == A[j][i]) {
                std::cout << "YES" << '\n';
                for(int k = 0; k <= M; k++) {
                    std::cout << (k % 2 == 0 ? i + 1 : j + 1) << " \n"[k == M];
                }
                return;
            }
        }
    }

    if(M % 2 == 1) {
        std::cout << "YES" << '\n';
        for(int k = 0; k <= M; k++) {
            std::cout << (k % 2 == 0 ? 1 : 2) << " \n"[k == M];
        }
        return;
    }

    if(M == 2) {
        if(N == 2) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        bool in_a = false;
        bool in_b = false;
        bool out_a = false;
        bool out_b = false;
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue; 
            }
            if(A[i][j] == 'a') {
                out_a = true;
            } else {
                out_b = true;
            }
        }
        
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            if(A[j][i] == 'a') {
                in_a = true;
            } else {
                in_b = true;
            }
        }

        if((in_a && out_a) || (in_b && out_b)) {
            std::vector<int> path;
            int u = -1;
            int v = -1;
            if(in_a && out_a) {
                for(int j = 0; j < N; j++) {
                    if(i == j) {
                        continue;
                    }
                    if(A[j][i] == 'a') {
                        u = j;
                        break;
                    }
                }
                for(int j = 0; j < N; j++) {
                    if(i == j) {
                        continue;
                    }
                    if(A[i][j] == 'a') {
                        v = j;
                        break;
                    }
                }
            } else {
                for(int j = 0; j < N; j++) {
                    if(i == j) {
                        continue;
                    }
                    if(A[j][i] == 'b') {
                        u = j;
                        break;
                    }
                }
                for(int j = 0; j < N; j++) {
                    if(i == j) {
                        continue;
                    }
                    if(A[i][j] == 'b') {
                        v = j;
                        break;
                    }
                }
            }
            
            if(M == 2) {
                path.push_back(u);
                path.push_back(i);
                path.push_back(v);
            } else if((M / 2) % 2 == 1) {
                for(int j = 0; j < M / 2 - 3; j++) {
                    path.push_back(j % 2 == 0 ? i : v);
                }                 
                path.push_back(i);
                path.push_back(v);
                path.push_back(u);
                path.push_back(i);
                path.push_back(v);
                path.push_back(u);
                path.push_back(i);

                for(int j = 0; j < M / 2 - 3; j++) {
                    path.push_back(j % 2 == 0 ? u : i);
                }
            } else {
                for(int j = 0; j < M / 2; j++) {
                    path.push_back(j % 2 == 0 ? i : u); 
                }
                path.push_back(i);
                for(int j = 0; j < M / 2; j++) {
                    path.push_back(j % 2 == 0 ? v : i);
                }
            }

            std::cout << "YES" << '\n';
            for(int j = 0; j <= M; j++) {
                std::cout << path[j] + 1 << " \n"[j == M];
            }
            return;
        }
    }

    std::cout << "NO" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
