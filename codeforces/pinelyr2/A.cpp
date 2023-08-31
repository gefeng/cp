#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, Q;
    std::cin >> N >> A >> Q;

    std::string S;
    std::cin >> S;

    int cnt_online = A;
    int cnt_know = A;
    int cnt_mayknow = A;
    
    for(int i = 0; i < Q; i++) {
        if(S[i] == '+') {
            cnt_online += 1;
            cnt_mayknow += 1;
        } else {
            cnt_online -= 1;
        }
        cnt_know = std::max(cnt_know, cnt_online);
    }

    if(cnt_mayknow < N) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << (cnt_know >= N ? "YES" : "MAYBE") << '\n';
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
