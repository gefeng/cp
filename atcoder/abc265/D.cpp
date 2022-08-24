#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    LL P, Q, R;
    cin >> N >> P >> Q >> R;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<LL> sum_set;
    sum_set.insert(0LL);
    LL sum = 0LL;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        sum_set.insert(sum);
    }

    for(LL s : sum_set) {
        if(sum_set.find(s + P) != sum_set.end() && 
           sum_set.find(s + P + Q) != sum_set.end() &&
           sum_set.find(s + P + Q + R) != sum_set.end()) {
            cout << "Yes" << '\n';
            return;
        }
    }    

    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    run_case();
}
