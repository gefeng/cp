#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1}; // R D L U
constexpr std::array<int, 4> DC = {1, 0, -1, 0};
constexpr std::array<char, 4> D = {'R', 'D', 'L', 'U'};

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;
    
    if(N % 2 == 1) {
        std::cout << "No" << '\n';
        return;
    }

    if(N % 2 == 0 && A % 2 == B % 2) {
        std::cout << "No" << '\n';
        return;
    }

    std::string ans = "";

    int r = 1;
    int c = 1;
    int d = 0;
    if(A % 2 == 1) {
        d = 0;
        while(r != A) {
            for(int i = 0; i < N - 1; i++) {
                ans.push_back(D[d]);
            }
            ans.push_back('D');
            d = (d + 2) % 4;
            r++;
        }
        
        d = 1;
        c = 1;
        while(true) {
            int nr = r + DR[d];
            int nc = c + DC[d];
            if(nc > N) {
                break;
            }
            if(nr != A || nc != B) {
                r = nr;
                c = nc;
                ans.push_back(D[d]);
                d = d == 1 || d == 3 ? 0 : (r % 2 == 0 ? 3 : 1);
            } else {
                // ans.push_back('D');
                // r++;
                if(c + 1 <= N) {
                    ans.push_back('R');
                    c++;
                } else {
                    break;
                }
                d = 0;
                d = d == 1 || d == 3 ? 0 : (r % 2 == 0 ? 3 : 1);
            }
        }

        d = 2;
        while(r + 1 <= N) {
            r++;
            ans.push_back('D');
            for(int i = 0; i < N - 1; i++) {
                ans.push_back(D[d]);
            }
            d = (d + 2) % 4;
        }
    } else {
        while(r != A - 1) {
            for(int i = 0; i < N - 1; i++) {
                ans.push_back(D[d]);
            }
            ans.push_back('D');
            d = (d + 2) % 4;
            r++;
        }

        d = 1;
        c = 1;
        while(true) {
            int nr = r + DR[d];
            int nc = c + DC[d];
            if(nc > N) {
                break;
            }
            if(nr != A || nc != B) {
                r = nr;
                c = nc;
                ans.push_back(D[d]);
                d = d == 1 || d == 3 ? 0 : (r % 2 == 0 ? 3 : 1);
            } else {
                if(c + 1 <= N) {
                    ans.push_back('R');
                    c++;
                } else {
                    break;
                }
                d = 0;
                d = d == 1 || d == 3 ? 0 : (r % 2 == 0 ? 3 : 1);
            }
        }

        d = 2;
        while(r + 1 <= N) {
            r++;
            ans.push_back('D');
            for(int i = 0; i < N - 1; i++) {
                ans.push_back(D[d]);
            }
            d = (d + 2) % 4;
        }
    }
    
    std::cout << "Yes" << '\n' << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
