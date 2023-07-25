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

    std::vector<int64_t> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    int64_t pre = 0;;
    std::set<int64_t> s;
    for(int i = 0; i < N - 1; i++) {
        s.insert(A[i] - pre);
        pre = A[i];
    }

    int cnt = 0;
    int x = 0;
    int y = 0;
    for(int i = 1; i <= N; i++) {
        if(s.find(i) == s.end()) {
            if(x == 0) {
                x = i;
            } else {
                y = i;
            }
            cnt += 1;
        }
    }

    if(cnt > 2) {
        std::cout << "NO" << '\n';
        return;
    }

    if(cnt == 1) {
        std::cout << "YES" << '\n'; 
        return;
    }


    s = std::set<int64_t>();
    bool found = false;
    pre = 0;
    for(int i = 0; i < N - 1; i++) {
        if(A[i] - pre == x + y) {
            if(!found) {
                s.insert(x);
                s.insert(y);
                found = true;
                pre = A[i];
                continue;
            }
        } 

        s.insert(A[i] - pre);
        pre = A[i];
    }

    for(int i = 1; i <= N; i++) {
        if(s.find(i) == s.end()) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
