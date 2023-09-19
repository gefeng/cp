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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> save_l(K + 1, -1);
    std::vector<int> save_r(K + 1, -1);
    std::vector<int> save_t(K + 1, -1);
    std::vector<int> save_b(K + 1, -1);
    
    std::vector<std::vector<int>> pos(K + 1);
    for(int i = 0; i < N; i++) {
        pos[A[i]].push_back(i); 
    }

    std::set<int> s;
    for(int i = K; i > 0; i--) {
        if(pos[i].empty()) {
            continue;
        }

        for(int p : pos[i]) {
            s.insert(p);
        } 

        save_l[i] = *s.begin();
        save_r[i] = *s.rbegin();
        save_t[i] = *s.begin();
        save_b[i] = *s.rbegin();
    }

    for(int i = 1; i <= K; i++) {
        int res = 0;
        if(save_l[i] != -1) {
            //std::cout << i << ' ' << save_l[i] << ' ' << save_r[i] << ' ' << save_t[i] << ' ' << save_b[i] << '\n';
            res = save_r[i] - save_l[i] + 1 + save_b[i] - save_t[i] + 1;
        }

        std::cout << res << " \n"[i == K];
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
