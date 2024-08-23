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
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += S[i] - '0';
    }

    if(cnt == 0 || cnt % 2 == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<std::pair<int, int>> ans;
    int st = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0' && S[(i - 1 + N) % N] == '1') {
            st = i;
            break;
        }
    }

    if(st == -1) {
        for(int i = 1; i < N; i++) {
            ans.emplace_back(0, i);
        }
    } else {
        std::vector<int> a;
        for(int i = st, j = 0; j < N; j++, i = (i + 1) % N) {
            if(S[i] == '1') {
                if(S[(i - 1 + N) % N] == '1') {
                    a.push_back(i);
                }
                continue;
            }
        
            ans.emplace_back(i, (i + 1) % N);
            if(i != st && S[(i - 1 + N) % N] == '1') {
                a.push_back(i);
            }
        }

        for(int v : a) {
            ans.emplace_back(st, v);
        }
    }
    
    assert(ans.size() == N - 1);

    std::cout << "YES" << '\n';
    for(int i = 0; i < N - 1; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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
