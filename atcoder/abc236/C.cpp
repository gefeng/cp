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

    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<string> s;
    for(int i = 0; i < M; i++) {
        string S;
        cin >> S;
        s.insert(S);
    }

    for(int i = 0; i < N; i++) {
        if(s.find(A[i]) != s.end()) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
