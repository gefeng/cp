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
    int N;
    cin >> N;

    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<string> s;
    for(int i = 0; i < N; i++) {
        if(A[i][0] == '!') {
            continue;
        }
        s.insert(A[i]);
    }

    for(int i = 0; i < N; i++) {
        if(A[i][0] == '!' && s.find(A[i].substr(1, A[i].size() - 1)) != s.end()) {
            cout << A[i].substr(1, A[i].size() - 1) << '\n';
            return;
        }
    }

    cout << "satisfiable" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
