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
    int sum = 0;
    int cnt_one = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
        if(A[i] == 1) {
            cnt_one += 1;
        }
    }

    int prefix = 0;
    int suffix = 0;
    std::map<int, int> m;
    for(int i = 0; i < N; ) {
        if(A[i] == 2) {
            int j = i;
            while(i < N && A[i] == 2) {
                i += 1;
            }
            m[j] = i - j;
            if(j == 0) {
                prefix = i - j;
            }
            if(i == N) {
                suffix = i - j;
            }
        } else {
            i += 1;
        }
    }

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int S;
            std::cin >> S;

            if(S > sum || (cnt_one == 0 && S % 2 == 1)) {
                std::cout << "No" << '\n';
                continue;
            }

            int x = sum - 2 * (prefix + suffix);
            if(S <= x + 2 * std::max(prefix, suffix)) {
                std::cout << "Yes" << '\n';
            } else {
                std::cout << (S % 2 == x % 2 ? "Yes" : "No") << '\n';
            }
        } else {
            int P, V;
            std::cin >> P >> V;
            P -= 1;
            
            if(A[P] == V) {
                continue;
            }

            if(V == 1) {
                sum -= 1;
                cnt_one += 1;

                auto it = m.upper_bound(P);
                it--;
                int h = it->first;
                int l = it->second;
                m.erase(it);
                if(P - h > 0) {
                    m[h] = P - h;
                }
                if(h + l - 1 - P > 0) {
                    m[P + 1] = h + l - 1 - P;
                }
            } else {
                sum += 1;
                cnt_one -= 1;

                if(P > 0 && P < N - 1 && A[P - 1] == 2 && A[P + 1] == 2) {
                    auto it1 = m.upper_bound(P);
                    auto it2 = std::prev(it1);
                    int h = it2->first;
                    int l = it1->second + it2->second + 1;
                    m.erase(it1);
                    m.erase(it2);
                    m[h] = l;
                } else if(P > 0 && A[P - 1] == 2) {
                    auto it = m.upper_bound(P);
                    it--;
                    it->second += 1;
                } else if(P < N - 1 && A[P + 1] == 2) {
                    auto it = m.upper_bound(P);
                    int l = it->second + 1;
                    m.erase(it);
                    m[P] = l;
                } else {
                    m[P] = 1;
                }
            }

            A[P] = V;

            prefix = !m.empty() && m.begin()->first == 0 ? m.begin()->second : 0;
            suffix = !m.empty() && m.rbegin()->first + m.rbegin()->second == N ? m.rbegin()->second : 0;
        }
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
