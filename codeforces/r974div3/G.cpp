#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <deque>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::deque<std::pair<int, int>> s;
    int now = 1;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int d = A[i].first - now;
        while(!s.empty() && d) {
            if(s.back().first + K - 1 < now) {
                break;
            } 

            if(s.back().second < M) {
                if(s.size() == 1) {
                    s.pop_back();
                    break;
                }
                auto [_, x] = s.back();
                s.pop_back();
                s.back().second += x;
                continue;
            }

            int d1 = s.back().first + K - now;
            int d2 = s.back().second / M;
            
            if(d1 <= d2) {
                int min_d = std::min(d, d1);
                d -= min_d;
                ans += min_d;
                now += min_d;
                s.back().second -= min_d * M;
                if(s.back().second == 0) {
                    s.pop_back();
                }
            } else {
                int min_d = std::min(d, d2); 
                d -= min_d;
                ans += min_d;
                now += min_d;
                s.back().second -= min_d * M;
                if(s.back().second == 0) {
                    s.pop_back();
                }
                if(min_d == 0) {
                    break;
                }
            }
        }

        s.emplace_back(A[i].first, A[i].second);
        now = A[i].first;

        int left = M;
        while(!s.empty() && left) {
            if(s.back().first + K - 1 < now) {
                break;
            }

            if(s.back().second <= left) {
                left -= s.back().second;
                s.pop_back();
            } else {
                s.back().second -= left;
                left = 0;
            }
        }

        if(left == 0) {
            ans += 1;
        }

        now += 1;
    }

    while(!s.empty()) {
        if(s.back().first + K - 1 < now) {
            break;
        }

        if(s.back().second < M) {
            if(s.size() == 1) {
                break;
            }
            auto [_, x] = s.back();
            s.pop_back();
            s.back().second += x;
            continue;
        }

        int d1 = s.back().first + K - now;
        int d2 = s.back().second / M;
        
        ans += std::min(d1, d2);
        now += std::min(d1, d2);
        
        if(d2 <= d1) {
            s.back().second -= M * d2;    
            if(s.back().second == 0) {
                s.pop_back();
            }
        } else {
            s.pop_back();
        }
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
