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
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int b = 1;
    int i = 0;

    while(i < N || !pq.empty()) {
        if(pq.empty()) {
            b = A[i].first;
        }

        while(i < N && A[i].first == b) {
            pq.push(A[i].second);
            i += 1;
        }

        if(!pq.empty() && pq.top() >= b) {
            pq.pop(); 
            b += 1;
        } else {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
