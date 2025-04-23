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

    std::vector<int> ans;
    int p = N - 1;
    bool ok = true;
    while(p >= 0 && ans.size() < N * 3) {
        if(S[p] == T[p]) {
            p -= 1;
            continue;
        } 

        bool flipped = false;
        for(int i = p - 1; i >= 0; i--) {
            if(S[i] == '1') {
                for(int j = i; j < p; j++) {
                    S[j + 1] = char(((S[j + 1] - '0') ^ 1) + '0');
                    if(ans.size() == N * 3) {
                        break;
                    }
                    ans.push_back(j);
                }

                flipped = true;
                break;
            }
        }

        if(!flipped) {
            ok = false;
            break;
        }
    }

    if(!ok) {
        std::cout << -1 << '\n';
        return;
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
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
