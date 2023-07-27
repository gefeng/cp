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
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    std::vector<int> save1r(N, 0);
    std::vector<int> save0l(N, 0);
    std::vector<int> save10;

    for(int i = 0; i < N - 1; i++) {
        if(S[i] == '1' && S[i + 1] == '0') {
            save10.push_back(i);
        }
    }

    int cnt1 = 0;
    for(int i = N - 1; i >= 0; i--) {
        save1r[i] = cnt1;
        if(S[i] == '0') {
            cnt1 = 0;
        } else {
            cnt1 += 1;
        }
    }

    int cnt0 = 0;
    for(int i = 0; i < N; i++) {
        save0l[i] = cnt0;
        if(S[i] == '0') {
            cnt0 += 1;
        } else {
            cnt0 = 0;
        }
    }

    std::set<std::pair<int, int>> s;
    int same_with_origin = 0;
    for(int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        bool sorted = true;
        auto it = std::lower_bound(save10.begin(), save10.end(), L);
        if(it != save10.end() && *it < R) {
            sorted = false;
        }

        if(sorted) {
            same_with_origin += 1;
        } else {
            s.emplace(L - save0l[L], R + save1r[R]);
        }
    }
     
    int ans = s.size() + (same_with_origin ? 1 : 0);
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
