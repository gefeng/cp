#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;
    
    vector<string> v;
    v.push_back(S.substr(0, N));
    v.push_back(S.substr(N, N));

    int cur = 0;
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        int A, B;
        cin >> A >> B;
        A -= 1;
        B -= 1;

        if(T == 1) {
            if(B < N) {
                swap(v[cur][A], v[cur][B]); 
            } else if(A > N - 1) {
                swap(v[cur ^ 1][A - N], v[cur ^ 1][B - N]);
            } else {
                swap(v[cur][A], v[cur ^ 1][B - N]);
            }
        } else {
            cur = cur ^= 1;
        }
    }

    if(cur == 0) {
        cout << v[0] + v[1] << '\n';
    } else {
        cout << v[1] + v[0] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
