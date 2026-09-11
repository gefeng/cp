#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> pre(N + 1, -1);
    std::vector<int> nxt(N + 1, -1);
    
    int head = A[0];
    int tail = A.back();
    for(int i = 0; i < N; i++) {
        pre[A[i]] = i == 0 ? -1 : A[i - 1];
        nxt[A[i]] = i == N - 1 ? -1 : A[i + 1];
    }

    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;
        if(X == tail) {
            continue;
        }
        
        int l = pre[X];
        int r = nxt[X];

        if(r != -1) {
            pre[r] = l; 
        }
        if(l != -1) {
            nxt[l] = r;
        }

        nxt[X] = -1;
        pre[X] = tail; 
        nxt[tail] = X;
        tail = X;
        if(head == X) {
            head = N == 1 ? head : r;
        }
    }

    int now = head;
    while(now != -1) {
        std::cout << now << ' ';
        now = nxt[now];
    }

    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
