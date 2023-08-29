#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> sorted(A);
    std::sort(sorted.begin(), sorted.end());

    std::map<int, int> m1; // value
    std::map<int, int> m2; // gap
    for(int x : A) {
        m1[x] += 1;
    }

    for(int i = 1; i < N; i++) {
        m2[sorted[i] - sorted[i - 1]] += 1;
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int P, X;
        std::cin >> P >> X;
        
        P -= 1;
    
        int old = A[P];
        if(m1[old] > 1) {
            m1[old] -= 1;
        } else {
            auto pre = m1.lower_bound(old);
            auto nxt = m1.upper_bound(old);
            if(pre != m1.begin()) {
                pre--;
                if(--m2[old - pre->first] == 0) {
                    m2.erase(old - pre->first);
                }
            }

            if(nxt != m1.end()) {
                if(--m2[nxt->first - old] == 0) {
                    m2.erase(nxt->first - old);
                }
            }

            if(pre->first != old && nxt != m1.end()) {
                m2[nxt->first - pre->first] += 1;
            }

            if(--m1[old] == 0) {
                m1.erase(old);
            }
        }

        if(m1.find(X) == m1.end()) {
            auto nxt = m1.upper_bound(X);
            auto pre = nxt;
            if(nxt == m1.end()) {
                if(pre != m1.begin()) {
                    pre--; 
                    m2[X - pre->first] += 1;
                } 
            } else {
                m2[nxt->first - X] += 1; 
                if(pre != m1.begin()) {
                    pre--;
                    m2[X - pre->first] += 1;
                    
                    if(--m2[nxt->first - pre->first] == 0) {
                        m2.erase(nxt->first - pre->first);
                    }
                }
            }
        }

        m1[X] += 1;
        A[P] = X;

        if(m2.empty()) {
            std::cout << A[0] << " \n"[i == Q - 1];
        } else {
            std::cout << m1.rbegin()->first + m2.rbegin()->first << " \n"[i == Q - 1];
        }
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
