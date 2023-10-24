#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;
map<int, int> steps;
int solve(int i){
    if(steps.find(i) != steps.end()){
        return steps[i];
    }
    int s = 1;
    if(i % 2 == 0){
        s = s + solve(i / 2);
    }else{
        s = s + solve(3*i + 1);
    }
    steps[i] = s;
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    steps[1] = 1; 
    int i, j;
    while(cin >> i){
        cin >> j;
        int res = 0;
        for(int k = i ; k <= j ; ++k){
            res = max(res, solve(k));
        }
        cout << i << " " << j << " " << res << "\n";
    }
    return 0;
}