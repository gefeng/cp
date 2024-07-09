#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S, T;
    std::cin >> S >> T;

    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'B') {
            cnt1 += 1;
        }
        if(T[i] == 'B') {
            cnt2 += 1;
        }
    }

    if(cnt1 != cnt2) {
        std::cout << -1 << '\n';
        return;
    }
    
    for(int i = 0; i < 2; i++) {
        S.push_back('.');
        T.push_back('.');
    }

    std::queue<std::string> q;
    std::set<std::string> vis;
    q.push(S);
    vis.insert(S);
    
    int d = 0;
    int n = N + 2;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            std::string s = q.front();
            q.pop();
            
            if(s == T) {
                std::cout << d << '\n';
                return;
            }

            int p = -1;
            for(int i = 0; i < n; i++) {
                if(s[i] == '.') {
                    p = i;
                    break;
                }
            }

            for(int i = 0; i < n - 1; i++) {
                if(s[i] != '.' && s[i + 1] != '.') {
                    std::string ns(s);
                    std::swap(ns[i], ns[p]);
                    std::swap(ns[i + 1], ns[p + 1]);
                    if(vis.find(ns) == vis.end()) {
                        q.push(ns);
                        vis.insert(ns); 
                    }
                }
            }
        }
        d += 1;
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
