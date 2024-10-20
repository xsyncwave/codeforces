#include <bits/stdc++.h>

const int maxn = 100;
int a[maxn];

void solve() {
    int n, rows; std::cin >> n >> rows;
    
    for(int i = 0; i < n; i++) std::cin >> a[i];
    
    int onecnt = 0, hapi = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) ++onecnt;
        else {
            hapi += a[i] / 2; onecnt += a[i] % 2; 
            rows -= a[i] / 2;
        }
    }
    hapi *= 2;
    
    if(rows < onecnt) hapi += (rows - (onecnt - rows));
    else hapi += onecnt;
    std::cout << hapi << std::endl;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    int t; std::cin >> t; while(t--) solve();
    return 0;
}
// g++ -std=c++20 <filename>.cpp
