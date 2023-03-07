#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i];
    }

    vector<int> ans(N, -1);
    int t = 1;
    int i = N - 1;
    set<int> s;
    for(int x : A) {
        if(i < 0) {
            break;
        }

        if(s.find(x) == s.end()) {
            ans[i--] = t;
            s.insert(x);
        }
             
        t += 1;
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
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
