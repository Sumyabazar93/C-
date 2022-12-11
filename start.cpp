// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define _ << " " <<
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define _GLIBCXX_DEBUG
 
using namespace std;

/*
// void update(ll p, ll l, ll r) {
// 	if(l == r){
// 		Max[p] = a[l];
// 		Min[p] = a[l];
// 		return ;
// 	}
// 	update(p * 2, l, (l + r) / 2);
// 	update( p * 2 + 1, (l + r) / 2 + 1, r);
	
// 	Max[p] = max(Max[p * 2], Max[p * 2 + 1]);
// 	Min[p] = min(Min[p * 2], Min[p * 2 + 1]);
// }
 
// ll maxSeg(ll p, ll l, ll r, ll s, ll f) {
// 	if(l >= s && r <= f){
// 		return Max[p];
// 	}
// 	if(l > f || r < s){
// 		return 0;
// 	}
// 	ll m, k;
// 	m = maxSeg(p * 2, l, (l + r) / 2, s, f);
// 	k = maxSeg(p * 2 + 1, (l + r) / 2 + 1, r, s, f);
	
// 	return max(m, k);
// }
 
// ll minSeg(ll p, ll l, ll r, ll s, ll f) {
// 	if(l >= s && r <= f){
// 		return Min[p];
// 	}
// 	if(l > f || r < s){
// 		return INT_MAX;
// 	}
// 	ll m, k;
// 	m = minSeg( p * 2, l, (l + r) / 2, s, f);
// 	k = minSeg(p * 2 + 1, (l + r) / 2 + 1, r, s, f);
	
// 	return min(m, k);
// }
 
 
// ll gcd(ll gcda, ll gcdb){
//     if (gcdb == 0)
//        return gcda;
//     return gcd(gcdb, gcda % gcdb); 
// }
// struct node{
//   int data;
//   struct node* left;
//   struct node* right;
// };
// class Node{
//   public:
//   int data;
//   Node* left;
//   Node* right;
 
//   Node(int val){
//     data = val;
//     left = NULL;
//     right = NULL;
//   }
// };
// Node* root = new Node(1);
// root->left = new Node(2);
// root->right = new Node(3);
// root->left->left = new Node(4);
 
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
 
    Node() {}
 
    Node(int _val) {
        val = _val;
    }
 
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
 
// deque<ll> D;
// D.push_back(x);
// D.push_front(x);
// D.push_back(x);
// D.pop_back(x);
// D.pop_front(x);
 
 
// Generating subsets
 
vector<int> subset;
void search(int k) {
    if (k == n) {
        for(int i = 0; i < subset.size(); i ++){
            cout << subset[i] << " ";
        }
        cout << endl;
    } else{
        search(k + 1);
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
    }
}
Method 2
 
for(int b = 0; b < (1 << n); b ++){
    vector<int> subset;
    for(int i = 0; i < n; i ++) {
        if(b & (1 << i)) subset.push_back(i);
    }
    for(int i = 0; i < subset.size(); i ++){
        cout << subset[i] << " ";
    }
}

// Dijkstra’s
priority_queue<pair<ll, ll> > Q;
Q.push(mp(0, x));
distance[x] = 0;
while(!Q.empty()){
    ll a = Q.top().ss; Q.pop();

    if(processed[a]) continue;
    processed[a] = true;

    for(i = 0; i < adj[a].size(); i ++){
        ll w = adj[a][i].ss;
        ll b = adj[a][i].ff;

        if(distance[a] + w < distance[b]){
            distance[b] = distance[a] + w;
            Q.push(mp(-distance[b], b));
        }
    }
}

// Generating permutations
 
vector<int> permutations;
bool chosen[10003] = {false};
 
void search(){
    if(permutations.size() == n){
        for(int i = 0; i < permutations.size(); i ++){
            cout << permutations[i] << " ";
        }
        cout << endl;
    }else{
        for(int i = 0; i < n; i ++){
            if(chosen[i]) continue;
            chosen[i] = true;
            permutations.push_back(i);
            search();
            chosen[i] = false;
            permutations.pop_back();
        }
    }
}
Method 2
    vector<int> permutation;
 
    for (int i = 0; i < n; i++) {
        permutation.push_back(i);
    }
    do {
        // process permutation
    } while (next_permutation(permutation.begin(),permutation.end()));
    
// Backtracking
ll column[1000], diag1[1000], diag2[1000];
void search(int y) {
    if (y == n) {
        // count++;
        return; 
    }
    for (int x = 0; x < n; x++) {
        cout << x _ y _ ":" _ x+y  _ x-y+n-1 << endl;
        if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}
Meet in the middle
Complexity time O(pow(2, n / 2))
[2, 4, 5, 9] subset sum  x = 15 ?
divide the list A[2, 4] ans B[5, 9]
generates all suvsets of A and B and stores their sums to a list Sa, Sb
for(int i = 0; i < x; i ++){
    if( (Sa[i] && Sa[x-i]) || (Sa[x-i] && S[i])){
        true;
    }
}

// bool CH(ll x, ll y) {
//     if(x >= 0 && x < n && y >= 0 && y < m) {
//         return true;
//     }
//     return false;
// }
 
*/

// Bit manipulation _____________

// Decimal to binary
// for(i = 0; i <= 31; i ++) {
//     if(n & (1 << i)) cout << 1;
//     else cout << 0;
// }
// if pow(2, k) = x ? -> ==== x & (x−1) = 0

// int x = 5328; // 00000000000000000001010011010000
// cout << __builtin_clz(x) << "\n"; // 19
// cout << __builtin_ctz(x) << "\n"; // 4
// cout << __builtin_popcount(x) << "\n"; // 5
// cout << __builtin_parity(x) << "\n"; // 1

 
// for (int i = 1; i <= n; i++) distance[i] = INF;
//     distance[x] = 0;
//     q.push({0,x});
//     while (!q.empty()) {
//         int a = q.top().second; q.pop();
//         if (processed[a]) continue;
//         processed[a] = true;
//         for (auto u : adj[a]) {
//            int b = u.first, w = u.second;
//            if (distance[a]+w < distance[b]) {
//                distance[b] = distance[a]+w;
//                q.push({-distance[b],b});
//            }
        
//         } 
//     }

// Union-find structure
// ll find(ll x) {
//     while(x != link[x]) {
//         x = link[x];
//     }
//     return x;
// }
// bool same(ll a, ll b) {
//     return find(a) == find(b);
// }
// void unite(ll a, ll b) {

//     a = find(a);
//     b = find(b);

//     if (sizel[a] < sizel[b]) swap(a,b);
//     if(sizel[a] == sizel[b] && a > b)swap(a, b);

//     sizel[a] += sizel[b];
//     link[b] = a;
// }

// ll gcd(ll gcda, ll gcdb){
//     if (gcdb == 0)
//        return gcda;
//     return gcd(gcdb, gcda % gcdb); 
// }
// ll mx[ ] = {0, 1, 0, -1};
// ll my[ ] = {1, 0, -1, 0};
// char mc[ ] = {'L', 'U', 'R', 'D'};

// cout << endl;
// RUN
// g++ "a".cpp -o "a".o
// ./'a'.o

void DEBUG() {
#ifdef _GLIBCXX_DEBUG
    std::cout  << "debug mode is enabled" << endl;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#else
    std::cout  << "debug mode is not enabled";
#endif
}

void solve() {
    ll n, m, j, i, s, h, k, p, q, l, u;

    
}

int main () {
    // DEBUG();
    FAST

    ll t;

    cin >> t;

    while(t --){
        solve();
    }

    return 0;
}