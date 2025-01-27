#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;

    std::vector<std::pair<char, int>> t(M);
    for(int i = 0; i < M; i++) {
        t[i] = {T[i], i};
    }

    std::sort(t.begin(), t.end(), [](const auto& x, const auto& y) {
                if(x.first == y.first) {
                    return x.second > y.second;
                }
                return x.first > y.first;
            });

    int last = -1;
    for(int i = 0, j = 0; i < N || j < M; ) {
        if(j == M) {
            break;
        }

        auto [c, p] = t[j];

        if(i == N) {
            if(c == t.back().first) {
                bool found = false;
                for(int k = last + 1; k < N; k++) {
                    if(S[k] == c) {
                        found = true; 
                        break;
                    }
                }
                if(found) {
                    break;
                }
            }

            while(j < M) {
                auto [c, p] = t[j];
                if(p > last) {
                    S[N - 1] = c;
                    last = p;
                }
                j += 1;
            }
            break;
        } else {
            if(S[i] < c) {
                S[i] = c;
                last = std::max(last, p);
                i += 1;
                j += 1;
            } else {
                i += 1;
            }
        }
    }

    std::cout << S << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
