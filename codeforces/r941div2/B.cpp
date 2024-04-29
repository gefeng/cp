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
    
    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    if(G[0][0] == G[N - 1][M - 1]) {
        std::cout << "Yes" << '\n';
        return;
    }

    if(G[0][M - 1] == G[N - 1][0]) {
        std::cout << "Yes" << '\n';
        return;
    }

    auto check1 = [&](char c) {
        if(G[0][0] != c) {
            bool ok1 = false;
            bool ok2 = false;
            for(int i = 0; i < M; i++) {
                if(G[0][i] == c) {
                    ok1 = true;
                    break;
                }
            } 

            for(int i = 0; i < N; i++) {
                if(G[i][0] == c) {
                    ok2 = true;
                } 
            }

            return ok1 && ok2;
        }  else {
            bool ok1 = false;
            bool ok2 = false;
            for(int i = 0; i < M; i++) {
                if(G[N - 1][i] == c) {
                    ok1 = true;
                    break;
                }
            } 

            for(int i = 0; i < N; i++) {
                if(G[i][M - 1] == c) {
                    ok2 = true;
                } 
            }

            return ok1 && ok2;
        }
    };

    auto check2 = [&](char c) {
        if(G[0][M - 1] != c) {
            bool ok1 = false;
            bool ok2 = false;
            for(int i = 0; i < M; i++) {
                if(G[0][i] == c) {
                    ok1 = true;
                    break;
                }
            } 

            for(int i = 0; i < N; i++) {
                if(G[i][M - 1] == c) {
                    ok2 = true;
                } 
            }

            return ok1 && ok2;
        }  else {
            bool ok1 = false;
            bool ok2 = false;
            for(int i = 0; i < M; i++) {
                if(G[N - 1][i] == c) {
                    ok1 = true;
                    break;
                }
            } 

            for(int i = 0; i < N; i++) {
                if(G[i][0] == c) {
                    ok2 = true;
                } 
            }

            return ok1 && ok2;
        }
    };

    if(check1('W') || check1('B') || check2('W') || check2('B')) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
    }
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
