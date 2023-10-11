#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case(int T) {
    int P;
    std::cin >> P;

    std::vector<int> pf;
    int x = P;
    for(int f = 2; f * f <= x; f++) {
        while(x % f == 0) {
            pf.push_back(f);
            x /= f;
        }
    }

    if(x > 1) {
        pf.push_back(x);
    }

    int n = pf.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += pf[i];
    }

    std::vector<int> ans;
    if(sum <= 41) {
        for(int i = 0; i < 41 - sum; i++) {
            ans.push_back(1);
        }        
        for(int i = 0; i < n; i++) {
            ans.push_back(pf[i]);
        }
    }

    std::cout << "Case #" << T << ": ";
    if(ans.empty()) {
        std::cout << -1 << '\n';
    } else {
        int sz = ans.size();
        std::cout << sz << ' ';
        for(int i = 0; i < sz; i++) {
            std::cout << ans[i] << " \n"[i == sz - 1];
        }
    }
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
