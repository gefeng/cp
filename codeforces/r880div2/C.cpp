#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int A, B, C;
    std::cin >> A >> B >> C;

    LL K;
    std::cin >> K;

    if(std::max(A, B) > C) {
        std::cout << -1 << '\n'; 
        return;
    }
    
    if(std::max(A, B) + 1 < C) {
        std::cout << -1 << '\n';
        return;
    }

    int la = 1;
    int ua = 1;
    int lb = 1;
    int ub = 1;
    int lc = 1;
    int uc = 1;
    for(int i = 0; i < A - 1; i++) {
        la *= 10;
    }
    ua = la * 10;

    for(int i = 0; i < B - 1; i++) {
        lb *= 10;
    }
    ub = lb * 10;

    for(int i = 0; i < C - 1; i++) {
        lc *= 10;
    }
    uc = lc * 10;
    
    LL cnt = 0LL;
    std::string ans = "";
    for(int a = la; a < ua; a++) {
        int l = std::max(lc - a, lb);
        int r = std::min(uc - a, ub);

        if(l >= r) {
            continue;
        }

        if(cnt + r - l < K) {
            cnt += r - l;
        } else {
            int b = l + K - cnt - 1LL;

            ans.append(std::to_string(a));
            ans.append(" + ");
            ans.append(std::to_string(b));
            ans.append(" = ");
            ans.append(std::to_string(a + b));

            std::cout << ans << '\n';
            return;
        }
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
