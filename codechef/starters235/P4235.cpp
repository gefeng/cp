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

    std::vector<int> a;
    std::vector<int> b;
    
    int pre = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] - 'a' >= pre) {
            a.push_back(i);
            pre = S[i] - 'a';
        } else {
            b.push_back(i);
        }
    }

    std::vector<int> aa(a);
    std::vector<int> bb(b);

    std::ranges::sort(a, [&](int i, int j) {
                return S[i] < S[j];
            });

    std::ranges::sort(b, [&](int i, int j) {
                return S[i] < S[j];
            });

    std::string ans(N, '?');
    for(int i = 0; i < a.size(); i++) {
        ans[aa[i]] = S[a[i]];
    }

    for(int i = 0; i < b.size(); i++) {
        ans[bb[i]] = S[b[i]];
    }

    std::cout << ans << '\n';
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
