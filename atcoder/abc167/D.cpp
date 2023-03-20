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

    LL K;
    cin >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    vector<int> vis(N, -1);
    int p = 0;
    int i = 0;
    while(vis[p] == -1) {
        vis[p] = i;
        p = A[p];
        i += 1;
    }

    int cycle = i - vis[p];
    int st = p;
    p = 0;
    while(p != st && K) {
        p = A[p];
        K -= 1LL; 
    }

    int rem = K % cycle;
    while(rem) {
        p = A[p];
        rem -= 1;
    } 

    cout << p + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
