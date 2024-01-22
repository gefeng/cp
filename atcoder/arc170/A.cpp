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
    int N;
    std::cin >> N;

    std::string S, T;
    std::cin >> S >> T;

    int ans = 0;
    std::set<int> aa;
    std::set<int> ba;
    for(int i = 0; i < N; i++) {
        if(S[i] == T[i] && S[i] == 'A') {
            aa.insert(i);
        }
        if(S[i] != T[i] && S[i] == 'B') {
            ba.insert(i);
        }

        if(S[i] != T[i] && S[i] == 'A') {
            if(!ba.empty()) {
                int j = *ba.begin();
                S[j] = 'A';
                S[i] = 'B';
                ans += 1;
                ba.erase(j);
                aa.insert(j);
            } else if(!aa.empty()) {
                S[i] = 'B';
                ans += 1;
            }
        }
    }

    bool has_bb = false;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == T[i] && S[i] == 'B') {
            has_bb = true;
        }

        if(S[i] != T[i] && S[i] == 'B' && has_bb) {
            S[i] = 'A';
            ans += 1;
        }
    }

    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) {
            ans = -1;
            break;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
