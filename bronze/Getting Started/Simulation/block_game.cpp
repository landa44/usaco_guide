#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
  int n ;
  cin >> n;

  vector<int> sol(26);

  while(n--){
    string x,y;
    cin >> x >> y;

    vector<int> alphx(26);
    vector<int> alphy(26);

    for(auto c: x) alphx[c-'a']++;
    for(auto c: y) alphy[c-'a']++;

    for(int i =0; i< 26; i++) sol[i]+= max(alphx[i], alphy[i]);
  }

  for(auto x: sol) cout << x << "\n";
  return 0;
}