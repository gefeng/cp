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

    set<int> s;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        s.insert(X);
    }

    cout << s.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
