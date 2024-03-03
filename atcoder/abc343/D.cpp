#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, T;
    std::cin >> N >> T;

    std::vector<int64_t> score(N, 0);
    std::map<int64_t, int> m;
    m[0] = N; 
    

    for(int i = 0; i < T; i++) {
        int A, B;
        std::cin >> A >> B;
        
        A -= 1;
        
        if(--m[score[A]] == 0) {
            m.erase(score[A]);
        }

        score[A] += B;
        m[score[A]] += 1;

        std::cout << m.size() << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
