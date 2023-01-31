#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B, C;
    cin >> A >> B >> C;

    if(A == B) {
        cout << "=" << '\n';
        return;
    }

    if(C % 2 == 0) {
        if(abs(A) == abs(B)) {
            cout << "=" << '\n';
            return;
        }
        cout << (abs(A) > abs(B) ? ">" : "<") << '\n';
        return;
    }

    if(A < 0 && B < 0) {
        cout << (A < B ? "<" : ">") << '\n';
        return;
    }

    if(A < 0) {
        cout << "<" << '\n';
        return;
    }

    if(B < 0) {
        cout << ">" << '\n';
        return;
    }

    cout << (A < B ? "<" : ">") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
