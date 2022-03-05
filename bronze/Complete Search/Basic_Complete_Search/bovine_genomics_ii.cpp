#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
  int n, m;
  cin >> n >> m;

  vector<string> spotty(n);
  vector<string> plain(n);

  for(auto &s: spotty) cin >> s;
  for(auto &s: plain) cin >> s;
  
  ll sol = m*(m-1)*(m-2)/6;
  for(int i =0; i< m; i++){
    for(int j=i+1; j< m; j++){
      for(int k = j+1; k<m; k++){
        unordered_set<string> gen;
        int same = 0;
        
        for(auto s: spotty) {
          string sub = "";
          ((sub+=s[i])+= s[j])+= s[k];

          gen.insert(sub);
        }

        for(auto s: plain) {
          string sub = "";
          ((sub+=s[i])+= s[j])+= s[k];

          if(gen.count(sub)){
            sol--;
            break;
          }
        }

      }
    }
  }

  cout << sol << endl;
  return 0;
}