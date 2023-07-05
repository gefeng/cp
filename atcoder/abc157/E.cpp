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

    std::string S;
    std::cin >> S;

    std::vector<std::set<int>> a(26);
    for(int i = 0; i < N; i++) {
        int c = S[i] - 'a';

        a[c].insert(i);
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int P;
            char C;
            std::cin >> P >> C;
            P -= 1;

            if(S[P] != C) {
                a[S[P] - 'a'].erase(P);
                a[C - 'a'].insert(P);
                S[P] = C;
            }
        } else {
            int L, R;
            std::cin >> L >> R;
            L -= 1;
            R -= 1;

            int cnt = 0;
            for(int j = 0; j < 26; j++) {
                auto it = a[j].lower_bound(L);
                if(it != a[j].end() && *it <= R) {
                    cnt += 1;
                }
            }

            std::cout << cnt << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
