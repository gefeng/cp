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
 
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= 1;
    }
 
    vector<int> pos(N);
    for(int i = 0; i < N; i++) {
        pos[A[i]] = i;
    }
 
    int cur = 1;
    while(cur < N && pos[cur] > pos[cur - 1]) {
        cur += 1;
    }
 
    if(cur != N) {
        int left = N - cur;
        cout << (left + K - 1) / K << '\n';
    } else {
        cout << 0 << '\n';
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
