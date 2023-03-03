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
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    priority_queue<int> pq;
    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        if(A[i]) {
            pq.push(A[i]);
        } else {
            if(!pq.empty()) {
                ans += pq.top();
                pq.pop();
            }
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
