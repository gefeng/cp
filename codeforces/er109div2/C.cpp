#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        char C;
        std::cin >> C;
        if(C == 'L') {
            A[i].second = 0;
        } else {
            A[i].second = 1;
        }
    }

    std::vector<int> odd;
    std::vector<int> eve;
    std::vector<int> ans(N, -1);
    for(int i = 0; i < N; i++) {
        if(A[i].first % 2 == 0) {
            eve.push_back(i);
        } else {
            odd.push_back(i);
        }
    }

    auto cmp = [&](const auto& x, const auto& y) {
        return A[x].first < A[y].first;
    };

    auto solve = [&](std::vector<int>& a) {
        int n = a.size();
        std::vector<int> s;
        for(int i = 0; i < n; i++) {
            if(!s.empty() && A[s.back()].second == 1 && A[a[i]].second == 0) {
                int t = (A[a[i]].first - A[s.back()].first) / 2;
                ans[s.back()] = t;
                ans[a[i]] = t;
                s.pop_back();
            } else {
                s.push_back(a[i]);
            }
        }
        
        if(!s.empty()) {
            n = s.size();
            int l = 0;
            int r = n - 1;
            while(l < n) {
                if(l + 1 < n && A[s[l]].second == 0 && A[s[l + 1]].second == 0) {
                    int t = (A[s[l]].first + A[s[l + 1]].first) / 2;
                    ans[s[l]] = t;
                    ans[s[l + 1]] = t;
                    l += 2;
                } else {
                    break;
                }
            }

            while(r >= 0) {
                if(r - 1 >= 0 && A[s[r]].second == 1 && A[s[r - 1]].second == 1) {
                    int t = (M - A[s[r]].first + M - A[s[r - 1]].first) / 2;
                    ans[s[r]] = t;
                    ans[s[r - 1]] = t;
                    r -= 2;
                } else {
                    break;
                }
            }

            if(l >= 0 && l < n && l < r) {
                int t = (M + A[s[l]].first + M - A[s[r]].first) / 2; 
                ans[s[l]] = t;
                ans[s[r]] = t;
            }
        } 
    };

    std::sort(eve.begin(), eve.end(), cmp);
    std::sort(odd.begin(), odd.end(), cmp);

    solve(eve);
    solve(odd);
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
