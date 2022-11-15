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

    vector<string> A(N);
    vector<string> B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    for(int i = 0; i < N; i++) {
        string s = A[i];
        string t = B[i];

        bool ok = true;
        for(int j = 0; j < N; j++) {
            if(i != j) {
                if(A[j] == s || B[j] == s) {
                    ok = false; 
                    break;
                }
            } 
        }

        if(ok) {
            continue;
        }

        ok = true;
        for(int j = 0; j < N; j++) {
            if(i != j) {
                if(A[j] == t || B[j] == t) {
                    ok = false;
                    break;
                }
            }
        }

        if(!ok) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
