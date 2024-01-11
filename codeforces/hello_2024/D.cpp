#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int INF = (int)1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::map<int, int> m;
    std::map<int, std::vector<int>> pos;
    for(int i = 0; i < N; i++) {
        m[A[i]] += 1;
        pos[A[i]].push_back(i); 
    }

    std::vector<int> pre(N, -1);
    std::vector<int> nxt(N, -1);
    for(int i = 1; i < N; i++) {
        pre[i] = i - 1;
    }
    
    for(int i = 0; i < N - 1; i++) {
        nxt[i] = i + 1;
    }

    bool ans = false;
    while(!m.empty()) {
        int max_v = m.rbegin()->first;
        int f = m.rbegin()->second;

        if(max_v == 0) {
            ans = f == 1;
            break;
        }

        for(int p : pos[max_v - 1]) {
            int cur = pre[p];
            while(cur != -1) {
                if(A[cur] == max_v) {
                    f -= 1;
                    cur = pre[cur];
                    pre[p] = cur;
                } else {
                    if(cur != -1) {
                        nxt[cur] = p;
                    }
                    break;
                }
            }
            cur = nxt[p];
            while(cur != -1) {
                if(A[cur] == max_v) {
                    f -= 1;
                    cur = nxt[cur];
                    nxt[p] = cur;
                } else {
                    if(cur != -1) {
                        pre[cur] = p;
                    }
                    break;
                }
            }
        } 

        if(f) {
            ans = false;
            break;
        }

        m.erase(max_v);
    }

    std::cout << (ans ? "Yes" : "No") << '\n';
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
