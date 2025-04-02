#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(K < N / 2) {
        std::cout << -1 << '\n';
        return;
    }

    if(N == 1) {
        if(K == 0) {
            std::cout << "A" << '\n' << "B" << '\n';
        } else {
            std::cout << "A" << '\n' << "A" << '\n';
        }
        return;
    }


    int lcs = 0;
    std::string s = "";
    std::string t = "";

    if(N / 2 == K) {
        for(int i = 0; i < N; i++) {
            s.push_back(i % 2 == 0 ? 'A' : 'B');
            t.push_back(i % 2 == 0 ? 'B' : 'C');
        }
    } else {
        while(true) {
            int n = s.size();
            if(N - n == K - lcs) {
                int i = 0;
                if(s.empty() || s.back() != 'A') {
                    while(s.size() != N) {
                        s.push_back(i == 0 ? 'A' : 'B');
                        t.push_back(i == 0 ? 'A' : 'B');
                        i ^= 1;
                    }    
                } else {
                    while(s.size() != N) {
                        s.push_back(i == 0 ? 'B' : 'A');
                        t.push_back(i == 0 ? 'B' : 'A');
                        i ^= 1;
                    }
                }
                break;
            } 
            
            if(lcs == K) {
                s.append("BA");
                t.append("CB");
                break;
            }

            if(n % 2 == 0) {
                s.push_back('A');
                t.push_back('A');
                lcs += 1;
            } else {
                s.push_back('B');
                t.push_back('C');
            }
        }
    }

    std::cout << s << '\n' << t << '\n';
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
