#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <deque>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    if(A[N - 1] != N && A[0] != N) {
        cout << -1 << '\n';
        return;
    }

    deque<int> q;
    for(int l = 0, r = N - 1; l <= r; ) {
        if(A[r] >= A[l]) {
            q.push_back(A[r--]);
        } else {
            q.push_front(A[l++]);
        }
    }
    
    for(int x : q) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
