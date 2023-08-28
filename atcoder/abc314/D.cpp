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

    int Q;
    std::cin >> Q;

    int last_lower = -1;
    int last_upper = -1;
    std::vector<int> last_modified(N, -1);
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        int P;
        char C;
        std::cin >> P >> C;
        if(T == 1) {
            P -= 1;
            S[P] = C;
            last_modified[P] = i;
        } else if(T == 2) {
            last_lower = i; 
        } else {
            last_upper = i;
        }
    }

    if(std::max(last_lower, last_upper) == -1) {
        std::cout << S << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(last_modified[i] == -1) {
            if(last_lower > last_upper) {
                if(S[i] >= 'A' && S[i] <= 'Z') {
                    S[i] = 'a' + S[i] - 'A';
                }
            } else {
                if(S[i] >= 'a' && S[i] <= 'z') {
                    S[i] = 'A' + S[i] - 'a';
                }
            }
        } else {
            if(last_modified[i] > std::max(last_lower, last_upper)) {
                continue;
            }

            if(last_lower > last_upper) {
                if(S[i] >= 'A' && S[i] <= 'Z') {
                    S[i] = 'a' + S[i] - 'A';
                }
            } else {
                if(S[i] >= 'a' && S[i] <= 'z') {
                    S[i] = 'A' + S[i] - 'a';
                }
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
