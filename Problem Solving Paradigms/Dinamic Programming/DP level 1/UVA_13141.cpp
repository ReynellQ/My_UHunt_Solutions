#include <bits/stdc++.h>

using namespace std;

int DP[86][2];

void init(){
    // 0 implies not branched, 1 implies to branch, 2 implies branched
    DP[1] = {0, 1};
    for(int i = 2 ; i < 86 ; ++i){
        DP[i][0] = DP[i - 1][0] + DP[i - 1][1]*2;
        DP[i][1] = DP[i - 1][1]/2;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n; 
    while(cin >> n, n){
        cout << (DP[i][0] + DP[i][1]) << "\n";
    }
}