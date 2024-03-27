#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    // abbbcacabbca
    // ...a...c
    // ...c...a
    //
    // a..c
    // c..a
    // a..a
    int N;
    std::cin >> N;

    std::string S, T;
    std::cin >> S >> T;

    std::vector<int> pre(N, -1);
    std::vector<int> pos;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'b') {
            pre[i] = i; 
        } else {
            pre[i] = i == 0 ? -1 : pre[i - 1];
        }
        
        if(S[i] == 'a' && T[i] == 'c') {
            pos.push_back(i);
        }
    }

    int j = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'c' && T[i] == 'a') {
            if(j < pos.size()) {
                int p = pos[j];
                if(p < i && pre[i] > p) {
                    std::swap(S[p], S[i]);
                    j += 1;
                }
            } 
        }
    }

    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
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
