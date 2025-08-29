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

    int p = 0;
    int ans = 0;
    while(p < N) {
        if(p == N - 1) {
            break;
        }
        if(S[p] == '(') {
            p += 2;
            ans += 1;
            continue;
        }

        if(S[p + 1] == ')') {
            p += 2;
            ans += 1;
            continue;
        }

        int j = p;
        p += 2;
        while(p + 1 < N && S[p] == '(' && S[p + 1] == '(') {
            p += 2;
        }
    
        if(S[p] == ')') {
            p += 1;
            ans += 1;
            continue;
        }

        if(p + 1 < N) {
            p += 2;
            ans += 1;
            continue;
        }

        p = j;
        break;
    }

    std::cout << ans << ' ' << N - p << '\n';
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
