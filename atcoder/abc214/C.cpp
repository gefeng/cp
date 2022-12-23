#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int INF = (int)2e9;

void run_case() {
    int N;
    cin >> N;

    vector<array<int, 3>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i][0];
        A[i][2] = i;
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i][1];
    }

    int min_t = INF;
    int st = -1;
    for(int i = 0; i < N; i++) {
        if(A[i][1] < min_t) {
            min_t = A[i][1];
            st = i;
        }
    } 

    vector<int> ans(N, INF);
    for(int i = 0; i < N; i++) {
        ans[i] = A[i][1];
    }

    int cur = st;
    int t = min_t;
    do {
        t = min(ans[cur], t);
        ans[cur] = t;
        t = ans[cur] + A[cur][0];
        cur = (cur + 1) % N;
    } while(cur != st);

    for(int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
