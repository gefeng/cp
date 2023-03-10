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

    sort(A.begin(), A.end(), greater<int>());

    priority_queue<int> pq;
    pq.push(A[1]);
    pq.push(A[1]);
    LL ans = A[0];
    for(int i = 2; i < N; i++) {
        int cur = pq.top();
        pq.pop();

        ans += cur;
        
        pq.push(A[i]);
        pq.push(A[i]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
