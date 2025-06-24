#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::string T;
    std::cin >> T;

    int bal = 0;
    int p = 0;
    int l = -1;
    int r = -1;
    int min_v = 0;
    int max_v = 0;
    std::vector<int> psum(N + 1, 0);
    std::vector<int> freq((N << 1) + 1, 0);
    std::string s(N, ' ');

    freq[N] = N;
    
    for(int i = 0; i < N; i++) {
        if(T[i] == 'L') {
            p = std::max(0, p - 1);
        } else if(T[i] == 'R') {
            p += 1;
        } else if(T[i] == '(') {
            bal -= s[p] == '(' ? 1 : (s[p] == ')' ? -1 : 0);
            bal += 1;
            s[p] = T[i];
        } else if(T[i] == ')') {
            bal -= s[p] == '(' ? 1 : (s[p] == ')' ? -1 : 0);
            bal -= 1;
            s[p] = T[i];
        } else {
            bal -= s[p] == '(' ? 1 : (s[p] == ')' ? -1 : 0);
            s[p] = T[i];
        }
        l = l == -1 ? p : std::min(l, p);
        r = r == -1 ? p : std::max(r, p);

        if(bal == 0) {
            for(int j = l; j <= r; j++) {
                freq[psum[j + 1] + N] -= 1;
                if(freq[psum[j + 1] + N] == 0 && min_v == psum[j + 1]) {
                    min_v += 1; 
                }
                if(freq[psum[j + 1] + N] == 0 && max_v == psum[j + 1]) {
                    max_v -= 1;
                }

                psum[j + 1] = psum[j] + (s[j] == '(' ? 1 : (s[j] == ')' ? -1 : 0));
                min_v = std::min(min_v, psum[j + 1]);
                max_v = std::max(max_v, psum[j + 1]);
                freq[psum[j + 1] + N] += 1;
            }
            l = -1;
            r = -1;
        }

        std::cout << (bal != 0 || min_v < 0 ? -1 : max_v) << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
