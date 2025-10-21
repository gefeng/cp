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
    
    std::vector<int> pre(26, -1);
    std::vector<int> nxt(26, -1);
    for(int i = 0; i < N - 1; i++) {
        if(pre[S[i] - 'a'] != -1) {
            std::cout << "Yes" << '\n';
            return;
        }
        pre[S[i] - 'a'] = i;
    }

    for(int i = N - 1; i > 0; i--) {
        if(nxt[S[i] - 'a'] != -1) {
            std::cout << "Yes" << '\n';
            return;
        }
        nxt[S[i] - 'a'] = i;
    }

    std::cout << "No" << '\n';
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
