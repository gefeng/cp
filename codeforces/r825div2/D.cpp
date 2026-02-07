#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int cnt = std::ranges::count(S, '0');
    if(cnt % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }
    
    std::vector<int> b;
    for(int i = 0; i < N * 2; i += 2) {
        if(S[i] != S[i + 1]) {
            if(S[i] == '0') {
                b.push_back(b.size() % 2 == 0 ? i : i + 1);
            } else {
                b.push_back(b.size() % 2 == 0 ? i + 1 : i);
            }
        }
    }

    //std::cout << S << '\n';

    int size = b.size();
    if(size) {
        char pre = S[b[0]];
        for(int i = 1; i < size; i++) {
            char now = S[b[i]];
            S[b[i]] = pre;
            pre = now;
        }
        S[b[0]] = pre;
    }

    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << b[i] + 1 << " \n"[i == size - 1];
    }


    for(int i = 0; i < N * 2; i += 2) {
        std::cout << i + 1 << ' ';
    }
    std::cout << std::endl;
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
