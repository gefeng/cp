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

    bool inc = true;
    for(int i = 1; i < N; i++) {
        if(S[i] < S[i - 1]) {
            inc = false;
        }
    }

    if(inc) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<std::vector<int>> pos(26);
    for(int i = 0; i < N; i++) {
        pos[S[i] - 'a'].push_back(i);
    }

    std::vector<int> seq(N, 0);
    int p = -1;
    for(char c = 'z'; c >= 'a'; c--) {
        for(int i : pos[c - 'a']) {
            if(i > p) {
                p = i;
                seq[p] = 1;
            }
        }
    }

    std::string s = "";
    std::string t = "";
    for(int i = 0; i < N; i++) {
        if(!seq[i]) {
            s.push_back(S[i]);
        } else {
            t.push_back(S[i]);
        }
    }

    std::sort(t.begin(), t.end());

    std::string merge = "";
    for(int i = 0, j = 0, k = 0; i < N; i++) {
        if(seq[i]) {
            merge.push_back(t[k++]);
        } else {
            merge.push_back(s[j++]);
        }
    }

    int ans = 0;
    for(char c : t) {
        if(c != t.back()) {
            ans += 1;
        }
    }

    std::sort(S.begin(), S.end());

    if(S == merge) {
        std::cout << ans << '\n';
        return;
    }

    std::cout << -1 << '\n';
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
