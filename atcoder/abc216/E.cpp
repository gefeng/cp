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
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    priority_queue<pair<LL, LL>> pq;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        pq.emplace(A[j], i - j);
    }

    LL ans = 0LL;
    while(K && !pq.empty()) {
        pair<LL, LL> cur = pq.top(); 
        pq.pop();

        LL v = cur.first;
        LL c = cur.second;

        if(pq.empty()) {
            if(v * c <= K) {
                ans += (1LL + v) * v / 2LL * c;
            } else {
                LL x = K / c;
                LL r = K % c;
                LL sum = (v + v - x + 1LL) * x / 2LL;
                sum *= c;
                sum += (v - x) * r;
                ans += sum;
            }
        } else {
            pair<LL, LL> top = pq.top();
            
            LL most = v - top.first;
            if(1LL * most * c <= K) {
                ans += (v + top.first + 1LL) * most / 2LL * c;
                K -= most * c;
                pq.pop();
                pq.emplace(top.first, top.second + c);
            } else {
                LL x = K / c;
                LL r = K % c;
                LL sum = (v + v - x + 1LL) * x / 2LL;
                sum *= c;
                sum += (v - x) * r;
                ans += sum;
                K = 0;
            }
        }
        //cout << v << ' ' << c << ' ' << ans << '\n';
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
