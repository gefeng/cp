#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<LL> dp_1(N + 1, 0LL); 
    dp_1[1] = A[0];
    for(int i = 2; i <= N; i++) {
        dp_1[i] = min(dp_1[i - 2] + A[i - 2], dp_1[i - 1] + A[i - 1]);
    } 

    int x = A[0];
    for(int i = 0; i < N - 1; i++) {
        A[i] = A[i + 1];
    }
    A[N - 1] = x;

    vector<LL> dp_2(N + 1, 0LL);
    dp_2[1] = A[0];
    for(int i = 2; i <= N; i++) {
        dp_2[i] = min(dp_2[i - 2] + A[i - 2], dp_2[i - 1] + A[i - 1]);
    }
    
    cout << min(dp_1[N], dp_2[N]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
