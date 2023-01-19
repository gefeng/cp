#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++) {
        pq.push(A[i]);
        if(pq.size() > K) {
            pq.pop(); 
        }
        if(pq.size() == K) {
            cout << pq.top() << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
