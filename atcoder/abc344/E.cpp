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

    std::map<int, int> m_pre;
    std::map<int, int> m_nxt;
    for(int i = 0; i < N; i++) {
        int pre = i == 0 ? 0 : A[i - 1];
        int nxt = i == N - 1 ? 0 : A[i + 1];
        m_pre[A[i]] = pre;
        m_nxt[A[i]] = nxt;
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int X, Y;
            std::cin >> X >> Y;
        
            int x_nxt = m_nxt[X];
            
            m_nxt[X] = Y;
            m_pre[x_nxt] = Y;

            m_pre[Y] = X;
            m_nxt[Y] = x_nxt;
        } else {
            int X;
            std::cin >> X;

            int pre = m_pre[X];
            int nxt = m_nxt[X];
            
            if(pre == 0) {
                m_pre[nxt] = 0;
            } else {
                m_nxt[pre] = nxt;
            }

            if(nxt == 0) {
                m_nxt[pre] = 0;
            } else {
                m_pre[nxt] = pre;
            }

            m_nxt.erase(X);
            m_pre.erase(X);
        }
    }

    int cur = 0;
    for(auto [k, pre] : m_pre) {
        if(pre == 0) {
            cur = k;
            break;
        }
    }

    while(cur) {
        std::cout << cur << ' ';
        cur = m_nxt[cur];
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
