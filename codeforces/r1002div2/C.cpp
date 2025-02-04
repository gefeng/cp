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
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::set<int>> suffix(N + 1);
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = N - 1; j >= 0; j--) {
            if(A[i][j] == 1) {
                cnt += 1;
            } else {
                break;
            }
        }

        suffix[cnt].insert(i);
    }

    int ans = 1;
    for(int i = 0; i < N; i++) {
        int mex = 1;
        int missing = 0;
        int where = -1;

        for(int j = N; j >= 0; j--) {
            if(suffix[j].find(i) != suffix[j].end()) {
                suffix[j].erase(i); 
                where = j;
                break;
            }
        }

        for(int j = 1; j <= N; j++) {
            mex = std::min(j + 1, mex + int(suffix[j].size()));
        }

        suffix[where].insert(i);

        ans = std::max(ans, mex);
    }

    std::cout << ans << '\n';
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
