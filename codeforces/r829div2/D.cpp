#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int N, X; 
    cin >> N >> X;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> cnt(X + 1, 0);
    for(int x : A) {
        cnt[x] += 1LL;
    }

    for(int i = 1; i <= X - 1; i++) {
        if(cnt[i] % (i + 1) != 0) {
            cout << "No" << '\n';
            return;
        }
        cnt[i + 1] += cnt[i] / (i + 1);
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
