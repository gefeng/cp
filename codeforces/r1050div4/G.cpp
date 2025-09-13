#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N, 0);
    std::vector<int> freq(N + 1, 0);
    for(int f = 1; f * f <= A[0]; f++) {
        if(A[0] % f == 0) {
            if(f != 1) {
                freq[f] += 1;
            }
            if(A[0] / f != 1 && A[0] / f != f) {
                freq[A[0] / f] += 1;
            }
        }
    }

    int max1 = 1;
    int max2 = -1;
    
    std::map<int, int> m;
    for(int f : freq) {
        if(f) {
            m[f] += 1;
        }
    }
    int g = A[0];
    for(int i = 1; i < N; i++) {
        int x = A[i];


        if(x == 1 && g == 1) {
            ans[i] = ans[i - 1];
            g = 1;
            continue;
        }
        if(x == 1 && g != 1) {
            ans[i] = i;
            g = 1;
            continue;
        }
        g = gcd(g, x);

        std::vector<int> div;
        for(int f = 1; f * f <= x; f++) {
            if(x % f == 0) {
                if(f != 1) {
                    div.push_back(f); 
                }
                if(x / f != 1 && f != x / f) {
                    div.push_back(x / f);
                }
            }
        }
        for(int d : div) {
            if(--m[freq[d]] == 0) {
                m.erase(freq[d]);
            }
            freq[d] += 1;
            m[freq[d]] += 1;
            max1 = std::max(max1, freq[d]);
        }


        if(m.size() > 1) {
            auto it = std::prev(std::prev(m.end()));
            max2 = it->first;
        }

        if(max1 != i + 1) {
            ans[i] = max1;
        } else {
            ans[i] = std::max(ans[i - 1], max2);
        }

    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
