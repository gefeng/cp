#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, M;
    std::cin >> N >> K >> M;

    std::string S;
    std::cin >> S;

    // abcccabba
    // abc cab ba

    std::array<int, 26> cnt = {};
    for(int i = 0; i < M; i++) {
        cnt[S[i] - 'a'] += 1;
    }

    for(int i = 0; i < K; i++) {
        if(cnt[i] < N) {
            std::cout << "No" << '\n';
            std::string missing = "";
            for(int j = 0; j < N; j++) {
                missing.push_back((char)(i + 'a'));
            }
            std::cout << missing << '\n';
            return;
        }
    }

    cnt = {};
    int tot = 0;
    std::string s = "";
    for(int i = 0; i < M; i++) {
        cnt[S[i] - 'a'] += 1;

        bool ok = true;
        for(int j = 0; j < K; j++) {
            if(cnt[j] == 0) {
                ok = false;
                break;
            }
        }

        if(ok) {
            tot += 1;
            cnt = {};
            s.push_back(S[i]);
        }
    }

    if(tot >= N) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::cout << "No" << '\n';
    for(int i = 0; i < K; i++) {
        if(cnt[i] == 0) {
            while(s.size() < N) {
                s.push_back((char)('a' + i));
            }
        }
    }

    std::cout << s << '\n';
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
