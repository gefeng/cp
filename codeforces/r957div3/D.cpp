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
    int N, M, K;
    std::cin >> N >> M >> K;

    std::string S;
    std::cin >> S;

    int cnt_swim = 0;
    int p = 0;
    while(true) {
        if(p >= N + 1) {
            std::cout << "YES" << '\n';
            return;
        }

        if(p == 0 || S[p - 1] == 'L') {
            int np = p;
            for(int i = M; i > 0; i--) {
                if(i + p >= N + 1 || S[i + p - 1] == 'L') {
                    np = i + p;
                    break;
                }
            }

            if(np == p) {
                for(int i = M; i > 0; i--) {
                    if(S[i + p - 1] == 'W') {
                        np = p + i;
                        break;
                    }            
                }
            }
            
            if(np == p) {
                break;
            }
            std::swap(np, p);
        } else {
            if(cnt_swim == K) {
                break;
            }

            if(p == N || S[p] == 'L' || S[p] == 'W') {
                p += 1;
                cnt_swim += 1;
            } else {
                break; 
            }
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
