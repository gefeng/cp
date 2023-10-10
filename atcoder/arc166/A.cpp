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

    std::string S, T;
    std::cin >> S >> T;

    for(int i = 0; i < N; ) {
        if(S[i] != 'C' && T[i] == 'C') {
            std::cout << "No" << '\n';
            return;
        }

        if(S[i] == 'C' && T[i] == 'C') {
            i += 1;
        } else {
            int j = i;
            while(i < N && T[i] != 'C') {
                i += 1; 
            }

            int cnt_a = 0;
            int cnt_b = 0;
            int cnt_c = 0;
            for(int k = j; k < i; k++) {
                if(T[k] == 'A') {
                    cnt_a += 1;
                } else {
                    cnt_b += 1;
                } 

                if(S[k] == 'C') {
                    cnt_c += 1;
                } else if(S[k] == 'A') {
                    cnt_a -= 1;
                } else {
                    cnt_b -= 1;
                }
            }

            if(cnt_a < 0 || cnt_b < 0) {
                std::cout << "No" << '\n';
                return;
            }

            for(int k = i - 1; k >= j; k--) {
                if(S[k] == 'C' && cnt_c && cnt_b) { 
                    S[k] = 'B';
                    cnt_c -= 1;
                    cnt_b -= 1;
                }
            }

            for(int k = i - 1; k >= j; k--) {
                if(S[k] == 'C') {
                    S[k] = 'A';
                }
            }

            std::vector<int> pos1;
            std::vector<int> pos2;
            for(int k = j; k < i; k++) {
                if(S[k] == 'B') {
                    pos1.push_back(k);
                }
                if(T[k] == 'B') {
                    pos2.push_back(k);
                }
            }

            for(int k = 0; k < pos1.size(); k++) {
                if(pos1[k] < pos2[k]) {
                    std::cout << "No" << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
