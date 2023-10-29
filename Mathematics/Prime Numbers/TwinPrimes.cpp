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
const int MAXN =  20000000;

vector<int> sieve(){
    vector<bool> primes(MAXN + 1);
    for(int i = 2 ; i*i <= MAXN ; ++i ){
        if(!primes[i]){
            for(int j = 2*i ; j <= MAXN ; j+= i){
                primes[j] = true;
            }
        }
    }
    vector<int> res;
    for(int i = 2 ; i<= MAXN ; ++i){
        if(primes[i] == false && primes[i + 2] == false){
            res.PB(i);
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    steps[1] = 1; 
    int s;
    vector<int> twin = sieve();
    while( cin >> s){
        int val = twin[s - 1];
        cout << "(" << val <<", " << (val+2) << ")\n";
    }
    return 0;
}