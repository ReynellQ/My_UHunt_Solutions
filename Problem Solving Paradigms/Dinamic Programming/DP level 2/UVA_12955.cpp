#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
int DP[MAXN];
vector<int> fact;

void init(){
    for(int i = 0 ; i < MAXN ; ++i){
        DP[i] = -1;
    }
    DP[0] = 0;
}

int solve(int N){
    if(N < 0){
        return INT_MAX;
    }
    if(DP[i] != -1){
        return DP[i];
    }
    int res = INT_MAX;
    for(int i = 0 ; i < fact.size() && fact[i] <= N; ++i){
        res = min(res, solve(N - fact[i]) + 1);
    }
    return DP[N] = res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; 
    fact.push_back(1);
    int f = 1, i = 2;
    while(f < MAXN){
        f*= i;
        fact.push_back(f);
        i++;
    } 
    while(cin >> N){
        init();
        cout << solve(N) << "\n";
    }
    
    
}