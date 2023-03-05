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

    vector<int> ans(N + 1, 0);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    ans[1] = 1;
    pq.push(A[0]);

    for(int k = 2; k <= N; k++) {
        while(!pq.empty()) {
            int d = pq.size();

            if(pq.top() < d + 1) {
                pq.pop();
            } else {
                break;
            }
        }

        pq.push(A[k - 1]); 
        ans[k] = pq.size();
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " \n"[i == N];
    }
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
