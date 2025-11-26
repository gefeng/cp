#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int MAX = 100;

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> freq(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        if(A[i] != -1) {
            freq[A[i]] += 1;
        }
    }

    std::vector<int> a(N, 0);
    for(int i = 0; i < N; i++) {
        if(A[i] == -1) {
            a[i] = -1;
        }
    }
    
    for(int i = 0, j = 0; i < N; i++) {
        if(A[i] == X) {
            while(j < N && a[j] == -1) {
                j += 1;
            }
            a[j++] = X;
        }
    }

    freq[X] = 0;
    std::vector<int> f(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        if(a[i] == 0) {
            int p = -1;
            for(int j = 1; j <= MAX; j++) {
                if(j != X && freq[j] && f[j] + 1 < f[X]) {
                    p = j;
                }
            } 
            if(p == -1) {
                int min_f = N + 1;
                for(int j = 1; j <= MAX; j++) {
                    if(j != X && freq[j] && f[j] < min_f) {
                        min_f = f[j];
                        p = j;
                    }
                }
            }
            a[i] = p;
            freq[p] -= 1;
            f[p] += 1;
        } else if(a[i] == X) {
            f[X] += 1;
        }
    }

    freq.assign(MAX + 1, 0);
    std::vector<int> votes(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        if(a[i] == -1) {
            int max_f = 0;
            int p = -1;
            int c = 0;
            for(int j = 1; j <= MAX; j++) {
                if(freq[j] > max_f) {
                    max_f = freq[j];
                    p = j;
                    c = 1;
                } else if(freq[j] == max_f) {
                    c += 1;
                }
            }

            if(p != -1 && c == 1) {
                votes[p] += 1;
            }
        } else {
            freq[a[i]] += 1;
            votes[a[i]] += 1;
        }
    }
    
    int max_v = *std::ranges::max_element(votes);
    int cnt = std::ranges::count(votes, max_v);
    std::cout << (votes[X] == max_v && cnt == 1 ? "Yes" : "No") << '\n';
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
