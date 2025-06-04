#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::string S;
    std::cin >> S;
    
    std::vector<std::pair<char, char>> B(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> B[i].first >> B[i].second;
    }

    std::deque<int> ba;
    std::deque<int> ca;
    std::deque<int> cb;
    std::deque<int> bc;
    
    for(int i = 0; i < Q; i++) {
        auto [x, y] = B[i];
        if(x == 'b' && y == 'a') {
            ba.push_back(i);
        } else if(x == 'c' && y == 'a') {
            ca.push_back(i);
        } else if(x == 'c' && y == 'b') {
            cb.push_back(i);
        } else if(x == 'b' && y == 'c') {
            bc.push_back(i);
        }
    }

    int cnt_cb = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'a') {
            continue;
        }

        if(S[i] == 'b' && !ba.empty()) {
            S[i] = 'a';
            ba.pop_front();
            continue;
        }

        if(S[i] == 'c' && !ca.empty()) {
            S[i] = 'a';
            ca.pop_front();
            continue;
        }

        if(S[i] == 'b' && !bc.empty() && !ca.empty()) {
            while(!bc.empty() && bc.back() > ca.back()) {
                bc.pop_back();
            }
            if(!bc.empty()) {
                S[i] = 'a';
                bc.pop_back();
                ca.pop_back();
                continue;
            }
        }

        if(S[i] == 'c' && !cb.empty() && !ba.empty()) {
            while(!cb.empty() && cb.back() > ba.back()) {
                cnt_cb += 1;
                cb.pop_back();
            }
            if(!cb.empty()) {
                S[i] = 'a';
                cb.pop_back();
                ba.pop_back();
                continue;
            }
        }

        if(S[i] == 'c') {
            if(cnt_cb) {
                S[i] = 'b';
                cnt_cb -= 1;
            } else if(!cb.empty()) {
                S[i] = 'b'; 
                cb.pop_back();
            }
        }
    }

    std::cout << S << '\n';
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
