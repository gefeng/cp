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

    vector<int> deg(N);
    bool is_star = false;
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        if(++deg[U] == N - 1) {
            is_star = true;
        }
        if(++deg[V] == N - 1) {
            is_star = true;
        }
    }

    cout << (is_star ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
