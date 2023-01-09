#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using LL = long long;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;

    vector<LL> psum(N + 1, 0LL);
    for(int i = 1; i <= M; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    priority_queue<int> max_q;
    for(int i = M - 1; i >= 0; i--) {
        while(psum[i + 1] < psum[M]) {
            int x = max_q.top();
            max_q.pop();

            psum[M] -= x;
            psum[M] += -x;

            ans += 1;
        }

        max_q.push(A[i]);
    }

    priority_queue<int, vector<int>, greater<int>> min_q;
    for(int i = M; i < N; i++) {
        min_q.push(A[i]);
        psum[i + 1] = psum[i] + A[i];
        
        while(psum[i + 1] < psum[M]) {
            int x = min_q.top();
            min_q.pop();

            psum[i + 1] -= x;
            psum[i + 1] += -x;

            ans += 1;
        }
    }

    cout << ans << '\n';
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
