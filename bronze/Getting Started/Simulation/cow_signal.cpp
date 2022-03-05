#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;

  for(int i = 0; i < n; ++i){
    string s;
    cin >> s;
    vector<char> aux;

    for(auto x: s)
      for(int j =0; j <k; ++j)
        aux.push_back(x);

    for(int j =0; j<k; ++j){
      for(auto x: aux) cout << x;
      cout << "\n";
    }    
  }
  return 0;
}