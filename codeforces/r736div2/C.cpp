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

    std::vector<int> cnt(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        if(U > V) {
            cnt[V] += 1;
        } else {
            cnt[U] += 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(cnt[i] == 0) {
            ans += 1;
        }
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        if(T == 1) {
            int U, V;
            std::cin >> U >> V;
            U -= 1;
            V -= 1;
            if(U > V) {
                if(++cnt[V] == 1) {
                    ans -= 1;
                }
            } else {
                if(++cnt[U] == 1) {
                    ans -= 1;
                }
            }
        } else if(T == 2) {
            int U, V;
            std::cin >> U >> V;
            U -= 1;
            V -= 1;
            if(U > V) {
                if(--cnt[V] == 0) {
                    ans += 1;
                }
            } else {
                if(--cnt[U] == 0) {
                    ans += 1;
                }
            }
        } else {
            std::cout << ans << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
