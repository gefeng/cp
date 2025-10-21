#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::string S;
    std::cin >> S;

    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        int j = i;
        int min_v = N;
        int max_v = -1;
        while(i < N) {
            min_v = std::min(min_v, A[i]); 
            max_v = std::max(max_v, A[i]);
            if(min_v == j && max_v == i) {
                break;
            }
            i += 1;
        }

        m[j] = i;
    }

    auto is_bad = [&](int i) {
        auto it = m.upper_bound(i);
        it--;
        auto [l, r] = *it;
        return i + 1 >= l && i + 1 <= r;
    };

    int cnt = 0;
    for(int i = 0; i < N - 1; i++) {
        if(S[i] == 'L' && S[i + 1] == 'R') {
            if(is_bad(i)) {
                cnt += 1;
            }
        }
    }
    
    for(int i = 0; i < Q; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        
        if(S[P] == 'L') {
            if(P && S[P - 1] == 'L') {
                if(is_bad(P - 1)) {
                    cnt += 1;
                }
            } 
            if(P + 1 < N && S[P + 1] =='R') {
                if(is_bad(P)) {
                    cnt -= 1;
                }
            }
            S[P] = 'R';
        } else {
            if(P && S[P - 1] == 'L') {
                if(is_bad(P - 1)) {
                    cnt -= 1;
                }
            }
            if(P + 1 < N && S[P + 1] == 'R') {
                if(is_bad(P)) {
                    cnt += 1;
                }
            }
            S[P] = 'L';
        }

        std::cout << (cnt == 0 ? "Yes" : "No") << '\n';
    }
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
