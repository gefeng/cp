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
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::string S;
    std::cin >> S;

    std::set<int> s;
    for(int i = 0; i < N; i++) {
        s.insert(i); 
    }
    
    std::vector<int> a;
    for(int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;

        L -= 1;
        R -= 1;

        auto it = s.lower_bound(L);
        std::set<int> removed;
        while(it != s.end() && *it <= R) {
            a.push_back(*it); 
            removed.insert(*it);
            it++;
        }

        for(int x : removed) {
            s.erase(x);
        }
    }

    int sz = a.size();
    std::vector<int> pos(N, -1);
    std::string t = "";
    int cnt_one = 0;
    int cnt_zero = 0;
    for(int i = 0; i < sz; i++) {
        pos[a[i]] = i;
        t.push_back(S[a[i]]);
    } 

    for(int i = 0; i < N; i++) {
        cnt_one += S[i] - '0';
    }

    int r = std::min(cnt_one, sz);
    for(int i = 0; i < r; i++) {
        if(t[i] == '0') {
            cnt_zero += 1;
        }
    } 

    for(int i = 0; i < Q; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        
        int p = pos[P];

        S[P] = S[P] == '0' ? '1' : '0';
        if(p != -1) {
            t[p] = t[p] == '0' ? '1' : '0';

            if(p < r && t[p] == '1') {
                cnt_zero -= 1;
            }
            if(p < r && t[p] == '0') {
                cnt_zero += 1;
            }
        } 
        
        if(S[P] == '1') {
            cnt_one += 1;
        } else {
            cnt_one -= 1;
        }

        int nr = std::min(cnt_one, sz);
        if(nr > r && t[r] == '0') {
            cnt_zero += 1; 
        }
        if(nr < r && t[nr] == '0') {
            cnt_zero -= 1;
        }


        r = nr;

        std::cout << cnt_zero << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
