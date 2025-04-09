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

    std::vector<int> P(N, -1);
    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int X;
        std::cin >> X;
        X -= 1;
        P[i] = X;
        G[X].push_back(i);
    }

    std::vector<int> color(N, 0);
    std::vector<std::vector<int>> not_matched(N);
    std::string ans = "";
    
    int c = 0;
    int cnt = 0;
    for(int i = 1; i < N; i++) {
        int p = P[i];
        if(i == 1) {
            ans.push_back('1');
            color[i] = c;
            color[p] = c;
            c += 1;
            continue;
        }

        if(!not_matched[p].empty()) {
            int x = not_matched[p].back();
            not_matched[p].pop_back();
            
            cnt -= 1;
            color[i] = c;
            color[x] = c;
            c += 1;
            ans.push_back(cnt == 0 ? '1' : '0');
        } else {
            not_matched[p].push_back(i);
            cnt += 1;
            ans.push_back('0');
        }
    }

    std::cout << ans << '\n';
    if(ans.back() == '1') {
        for(int i = 0; i < N; i++) {
            std::cout << color[i] + 1 << " \n"[i == N - 1];
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
