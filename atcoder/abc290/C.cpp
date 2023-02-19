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
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    set<int> s;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        s.insert(A[i]);
    }


    int mex = 0;
    for(int x : s) {
        if(x > mex) {
            break;
        }
        
        if(x == mex) {
            mex += 1;
            K -= 1;
            if(K == 0) {
                break;
            }
        }
    }

    cout << mex << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
