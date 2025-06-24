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

    std::vector<std::string> A(N);
    std::multiset<std::string> s;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        s.insert(A[i]);
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        s.erase(s.find(A[i]));
        if(s.find(A[i]) == s.end()) {
            s.insert(A[i]);
            continue;
        }

        bool end = false;
        for(int j = 0; j < 4; j++) {
            for(char d = '0'; d <= '9'; d++) {
                char c = A[i][j];
                A[i][j] = d;
                if(s.find(A[i]) == s.end()) {
                    s.insert(A[i]);
                    cnt += 1;
                    end = true;
                    break;
                }
                A[i][j] = c;
            }
            if(end) {
                break;
            }
        }
    }

    std::cout << cnt << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << A[i] << '\n';
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
