#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> A(N);    
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            int X;
            cin >> X;
            sum += X;
        }
        A[i] = {sum, i};
    }

    sort(A.begin(), A.end(), greater<pair<int, int>>()); 

    vector<bool> ans(N, false);
    for(int i = 0; i < K; i++) {
        ans[A[i].second] = true;
    }

    for(int i = K; i < N; i++) {
        ans[A[i].second] = A[i].first + 300 >= A[K - 1].first;
    }

    for(int i = 0; i < N; i++) {
        cout << (ans[i] ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
