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

ll f(ll d, ll a, ll b){
    double c = a*d + 1;
    c = ceil(c/b);
    return c;
}
int bs(ll a, ll b, long double n){
    ll res = -1;
    for(int d = 1 ; d <= 1e7 ; ++d ){
        ll c = f(d, a, b);
        long double diff = (b*c - a*d);
        double aux = n;
        aux = aux*b*d;
        //cout << c << "/" << d << " ->"<< diff << " < "  << aux<<"\n";
        if(diff <= aux && a!=c && b!=d){
            return d;
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll A, B;
    long double n;
    while(cin >> A){
        cin >>B >> n;
        int d = bs(A, B, n);
        cout << f(d, A, B)<<" "<<d << "\n";
    }
    return 0;
}