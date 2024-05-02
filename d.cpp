/* 

    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T> void chmin (T &a, T b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T b) {if (a < b) swap(a, b);}


void solve() {
    int n, k, x, y;
    cin >> n >> k >> x >> y, --x, --y;

    vector<int> p(n);
    for (auto &x : p) 
        cin >> x, --x;

    vector<int> a(n);
    for (auto &x : a) 
        cin >> x;


    auto getPath = [&] (int u) {
        vector<int> path, seen(n);
        while (!seen[u]) {
            path.push_back(a[u]);
            seen[u] = 1, u = p[u];
        }
        return path;
    };

    vector<int> a_path = getPath(x), b_path = getPath(y);

    auto getScore = [&] (vector<int> path) {
        const int m = path.size();
        ll score = 0, sum = 0;
        for (int i = 0; i < min(m, k); ++i) {
            score = max({score, path[i] * 1ll * (k - i) + sum});
            sum += path[i];
        }
        score = max(score, (k - m) * 1ll * path.back() + sum);
        return score;
    };

    if (getScore(a_path) > getScore(b_path)) {
        cout << "Bodya\n";
    } else if (getScore(a_path) < getScore(b_path)) {
        cout << "Sasha\n";
    } else {
        cout << "Draw\n";
    }


} 


int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE   
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifndef ONLINE_JUDGE
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
