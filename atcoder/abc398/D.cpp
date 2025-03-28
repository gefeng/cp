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
    int N, R, C;
    std::cin >> N >> R >> C;
    
    std::string S;
    std::cin >> S;
    
    std::set<std::pair<int, int>> path;
    std::string ans(N, '0');
    int r = 0;
    int c = 0;
    path.emplace(r, c);
    for(int i = 0; i < N; i++) {
        if(S[i] == 'N') {
            r += 1; 
            R += 1;
        } else if(S[i] == 'S') {
            r -= 1;
            R -= 1;
        } else if(S[i] == 'E') {
            c -= 1;
            C -= 1;
        } else {
            c += 1;
            C += 1;
        }
        path.emplace(r, c);
        if(path.find({R, C}) != path.end()) {
            ans[i] = '1';
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
