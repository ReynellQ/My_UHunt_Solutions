    #include <bits/stdc++.h>
    using namespace std;

    vector<int> p, c;

    void count_sort(vector<int> &p, vector<int> &c){
        int n = p.size();
        vector<int> cnt(n), p_new(n), pos(n);
        pos[0] = 0;
        for(auto x : c) cnt[x]++;
        for(int i = 1 ; i < n ; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
        for(auto x : p){
            int i = c[x];
            p_new[pos[i]] = x;
            pos[i]++;
        }
        p = p_new;
    }
    vector<int> suffix_array(string &s){
        s+=" ";
        int n = s.size();
        p.resize(n);
        c.resize(n);
        vector<pair<char, int>> a(n);
        for(int i = 0 ; i < n ; ++i) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for(int i = 0 ; i < n ; ++i) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1 ; i < n ; ++i) c[p[i]] = a[i].first == a[i - 1].first ? c[p[i - 1]] : c[p[i - 1]] + 1;
        int k = 0, shift;
        while( (1<<k) < n ){
            shift = 1<<k;
            for(int i = 0 ; i<n ; ++i)
                p[i] = (p[i] - (1<<k) +  n) % n;
            count_sort(p,c);
            vector<int> c_new(n);
            c_new[p[0]] = 0;
            for(int i = 1 ; i < n ; ++i){
                pair<int, int> prev = {c[p[i - 1]], c[ (p[i - 1] + shift) % n]};
                pair<int, int> now = {c[p[i]], c[(p[i] + shift) % n]};
                if(prev == now) c_new[p[i]] = c_new[p[i - 1]];
                else c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
            c = c_new;
            k++;
        }  
        return p;
    }

    vector<int> lcp(vector<int> &p, vector<int> &c, string &s){
        int n = p.size();
        vector<int> lcp(n);
        int k = 0;
        for(int i = 0 ; i < n - 1 ; ++i){
            int pi = c[i];
            int j = p[pi - 1];
            while(s[i + k] == s[j + k]) k++;
            lcp[pi] = k;
            k = max(k - 1, 0);
        }
        return lcp;
    }
    int main(){
        // ifstream cin("input.txt");
        // ofstream cout("output.txt");
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t; cin >>t;
        while(t--){
            string s; cin >>s;
            vector<int> sa = suffix_array(s);
            vector<int> LCP = lcp(p, c, s);
            // for(auto &x : sa)
            //     cout << s.substr(x, sa.size())<<"\n";
            // for(auto &x : LCP)
            //     cout << x<<"\n";
            // cout << "\n";
            int MAX = 0;
            int ocurrences = 0;
            int maxOcurrences = 0;
            int suffix = -1;
            for(int i = 1 ; i< s.size() ; ++i){
                if(LCP[i] > MAX){
                    suffix = p[i];
                    MAX = LCP[i];
                    ocurrences = 2;
                    maxOcurrences = 2;
                }else if( LCP[i] == MAX){
                    if(LCP[i - 1] == MAX)
                        ocurrences++;
                    else{
                        maxOcurrences = max(maxOcurrences, ocurrences);
                        ocurrences = 2;
                    }   
                }
            }
            maxOcurrences = max(maxOcurrences, ocurrences);
            if(suffix == -1)
                cout << "No repetitions found!\n";
            else
                cout << s.substr(suffix, MAX)<<" "<<maxOcurrences<<"\n";
        }
    }