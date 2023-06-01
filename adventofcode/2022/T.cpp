#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using LL = long long;

constexpr LL KEY = 811589153LL;

void run_case() {
    std::vector<std::pair<LL, int>> A;
    
    std::string S;
    std::set<int> s;
    int cnt = 0;
    while(getline(std::cin, S)) {
        A.emplace_back(KEY * stoi(S), cnt++);
    }

    int n = A.size();
    std::vector<std::pair<LL, int>> now(A);
    for(int k = 0; k < 10; k++) {
        for(int i = 0; i < n; i++) {
            LL t_v = A[i].first;
            int t_i = A[i].second;

            int p = 0;
            while(p < n && (now[p].first != t_v || now[p].second != t_i)) {
                p += 1;
            }

            std::vector<std::pair<LL, int>> tmp;
            for(int j = 0; j < n; j++) {
                if(now[j] != A[i]) {
                    tmp.emplace_back(now[j]);
                }
            }

            LL d = A[i].first % (n - 1);
            p = p % (n - 1);
            p = (p + d + (n - 1)) % (n - 1);
            if(A[i].first < 0 && p == 0) {
                p = n - 1;
            } else if(A[i].first > 0 && p == n - 1) {
                p = 0;
            }

            std::vector<std::pair<LL, int>> nxt;
            for(int j = 0; j < p; j++) {
                nxt.emplace_back(tmp[j]);
            }
            
            nxt.emplace_back(A[i]);
            
            for(int j = p; j < n - 1; j++) {
                nxt.emplace_back(tmp[j]);
            }

            
            /*if(now[p].first < 0) {
                for(int j = 0; j < np; j++) {
                    if(now[j] != A[i]) {
                        nxt.emplace_back(now[j].first, now[j].second);
                    }
                } 

                nxt.emplace_back(t_v, t_i);
                
                for(int j = np; j < n; j++) {
                    if(now[j] != A[i]) {
                        nxt.emplace_back(now[j]);
                    }
                }
            } else if(now[p].first > 0) {
                for(int j = 0; j < np; j++) {
                    if(now[j] != A[i]) {
                        nxt.emplace_back(now[j].first, now[j].second);
                    }
                } 

                nxt.emplace_back(t_v, t_i);
                
                for(int j = np; j < n; j++) {
                    if(now[j] != A[i]) {
                        nxt.emplace_back(now[j].first, now[j].second);
                    }
                }
            } else {
                nxt = std::vector<std::pair<int, int>>(now);
            }*/

            std::swap(now, nxt);
            /*for(int i = 0; i < n; i++) {
                std::cout << now[i].first << " \n"[i == n - 1];
            }*/
        
        }
    }

    int p_0 = -1;
    for(int i = 0; i < n; i++) {
        if(now[i].first == 0) {
            p_0 = i;
            break;
        } 
    }

    LL ans = now[(p_0 + 1000) % n].first + now[(p_0 + 2000) % n].first + now[(p_0 + 3000) % n].first;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
