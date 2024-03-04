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

    auto query = [](int a, int b, int c, int d) {
        std::cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
        char C;
        std::cin >> C;
        return C == '=' ? 0 : (C == '<' ? -1 : 1);
    };
    
    int p1 = 0;
    int p2 = -1;
    for(int i = 1; i < N; i++) {
        int res = query(p1, p1, i, i);
        if(res == -1) {
            p1 = i;
        }
    }

    std::vector<int> cand;
    for(int i = 0; i < N; i++) {
        if(i != p1) {
            if(p2 == -1) {
                p2 = i; 
                cand.push_back(p2);
            } else {
                int res = query(i, p1, p2, p1);
                if(res == 0) {
                    cand.push_back(i);
                } else if(res == 1) {
                    p2 = i;
                    cand.clear();
                    cand.push_back(p2);
                }
            }
        }
    }

    int n = cand.size();
    p2 = cand[0];
    for(int i = 1; i < n; i++) {
        int res = query(p2, p2, cand[i], cand[i]);
        if(res == 1) {
            p2 = cand[i];
        }
    }

    std::cout << "! " << ' ' << p1 << ' ' << p2 << std::endl;
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
