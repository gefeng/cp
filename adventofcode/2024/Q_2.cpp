#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int next_int(std::string S, int& p) {
    int n = S.size();
    int x = 0;
    while(p < n && !isdigit(S[p])) {
        p += 1;
    }
    if(p == n) {
        return -1;
    }
    while(p < n && isdigit(S[p])) {
        x = x * 10 + S[p++] - '0';
    }
    return x;
}

void run_case() {
    std::array<int64_t, 3> R = {};
    std::vector<int> A;
    for(int i = 0; i < 5; i++) {
        std::string S;
        std::getline(std::cin, S);
        int p = 0;
        if(i < 3) {
            R[i] = next_int(S, p);
        } else if(i == 4) {
            while(true) {
                int x = next_int(S, p); 
                if(x == -1) {
                    break;
                }
                A.push_back(x);
            }
        }
    }

    auto get_literal = [&](int operand) {
        if(operand < 4) {
            return int64_t(operand);
        } 
        return R[operand - 4];
    };
    
    int n = A.size();
    std::vector<int64_t> cand;
    cand.push_back(0);
    for(int i = n - 1; i >= 0; i--) {
        std::vector<int64_t> n_cand;
        for(int64_t a : cand) {
            for(int64_t b = a * 8; b < (a + 1) * 8; b++) {
                R[0] = b;
                int p = 0;
                bool found = false;
                while(true) {            
                    int opcode = A[p];
                    int operand = A[p + 1];
                    if(opcode == 0) {
                        int64_t x = R[0];
                        int64_t y = get_literal(operand);
                        if(y >= 63) {
                            R[0] = 0;
                        } else {
                            R[0] = x / int64_t(powl(2, y));
                        }
                    } else if(opcode == 1) {
                        int64_t x = R[1];
                        R[1] = x ^ operand;
                    } else if(opcode == 2) {
                        int64_t x = get_literal(operand); 
                        R[1] = x % 8;
                    } else if(opcode == 3) {
                        if(R[0] != 0) {
                            p = operand;
                            continue;
                        } 
                    } else if(opcode == 4) {
                        R[1] = R[1] ^ R[2];
                    } else if(opcode == 5) {
                        int64_t x = get_literal(operand);
                        x %= 8;
                        if(x == A[i]) {
                            n_cand.push_back(b);
                        } 
                        break;
                        //res.push_back(x);
                        // if(res.size() > n) {
                        //     break;
                        // }
                        // if(res.back() != A[res.size() - 1]) {
                        //     break;
                        // }
                    } else if(opcode == 6) {
                        int64_t x = R[0];
                        int64_t y = get_literal(operand);
                        if(y >= 63) {
                            R[1] = 0;
                        } else {
                            R[1] = x / int64_t(powl(2, y));
                        }
                    } else if(opcode == 7) {
                        int64_t x = R[0];
                        int64_t y = get_literal(operand);
                        if(y >= 63) {
                            R[2] = 0;
                        } else {
                            R[2] = x / int64_t(powl(2, y));
                        }
                    }
                    p += 2;
                }
            }            
        }
        std::swap(cand, n_cand);
    }

    //std::cout << int64_t(powl(2, 45)) * 3 << '\n';

    std::sort(cand.begin(), cand.end());
    std::cout << cand[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
