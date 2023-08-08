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

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::pair<int, int>> d(N);
    for(int i = 0; i < N; i++) {
        d[i].first = A[i] - B[i];
        d[i].second = i;
    } 

    std::sort(d.begin(), d.end());
    
    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(d[i].first == d.back().first) {
            ans.push_back(d[i].second + 1);
        }
    } 

    std::sort(ans.begin(), ans.end());

    int sz = ans.size();
    std::cout << sz << '\n';
    for(int i = 0; i < sz; i++) {
        std::cout << ans[i] << " \n"[i == sz - 1];
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
