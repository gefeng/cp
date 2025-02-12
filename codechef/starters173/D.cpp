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
    std::vector<int> pos(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]] = i + 1;
    }

    if(A[0] != 1 && A[0] != 2) {
        std::cout << "No" << '\n';
        return;
    }
    
    if(A.back() != 1 && A.back() != 2) {
        std::cout << "No" << '\n';
        return;
    }

    std::map<int, int> m_1;
    std::map<int, int> m_2;
    m_1[2] = N - 1;
    m_2[N - 2] = 1;
    for(int i = 3; i <= N; i++) {
        int seat = pos[i]; 
    
        auto it = std::prev(m_1.upper_bound(seat));
        auto [l, r] = *it;
        
        int d = std::min(seat - l, r - seat);

        int max_d = m_2.rbegin()->first;
        int mid = (max_d + 1) / 2;
        if(std::min(mid - 1, max_d - mid) != d) {
            std::cout << "No" << '\n';
            return;
        }
        
        m_1.erase(l);
        if(--m_2[r - l + 1] == 0) {
            m_2.erase(r - l + 1);
        }

        if(seat - 1 >= l) {
            m_1[l] = seat - 1;
            m_2[seat - l] += 1;
        }
        if(seat + 1 <= r) {
            m_1[seat + 1] = r;
            m_2[r - seat] += 1;
        }
    }

    std::cout << "Yes" << '\n';
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
