#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> B(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    multiset<int> ms;
    for(int i = 0; i < N; i++) {
        ms.insert(B[i]);
    }

    vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        auto head = ms.begin();
        auto tail = ms.end();
        tail--;
        if(A[i] != *tail) {
            ans[i] = *tail;
            ms.erase(tail);
        } else {
            ans[i] = *head;
            ms.erase(head);
        }
    }

    int len = 0;
    int st = -1;
    int ed = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] == ans[i]) {
            st = st == -1 ? i : st; 
            ed = i;
            len += 1;
        }
    }

    if(len) {
        int z = A[st];
        for(int i = 0, j = st; A[i] != z && j <= ed; i++) {
            if(ans[i] != z) {
                swap(ans[i], ans[j]);
                j += 1;
            }
        }

        for(int i = 0; i < N; i++) {
            if(ans[i] == A[i]) {
                cout << "No" << '\n';
                return;
            }
        }
    }

    cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
