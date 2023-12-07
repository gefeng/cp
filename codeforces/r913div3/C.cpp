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

    /*std::vector<std::pair<char, int>> s;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }

        int cnt = i - j;
        while(!s.empty()) {
            if(s.back().first == S[j]) {
                cnt += s.back().second;
                s.pop_back();
            } else {
                if(cnt == 1 && s.back().second == 1) {
                    break;
                }

                if(s.back().second > cnt) {
                    s.back().second -= cnt;
                    cnt = 0;
                    break;
                }

                cnt -= s.back().second;
                s.pop_back();
                if(cnt == 0) {
                    break;
                }
            }
        }

        if(cnt) {
            s.emplace_back(S[j], cnt); 
        }
    }*/

    std::array<int, 26> cnt = {};
    for(int i = 0; i < N; i++) {
        cnt[S[i] - 'a'] += 1;
    }

    for(int i = 0; i < 26; i++) {
        if(cnt[i] > N / 2) {
            for(int j = 0; j < 26; j++) {
                cnt[i] -= i == j ? 0 : cnt[j];
            }
            std::cout << cnt[i] << '\n';
            return;
        }
    } 

    std::cout << N % 2 << '\n';
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
