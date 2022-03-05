#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);
  string s, t;
  cin >> s >> t;

  int beg = 0;
  int m=0;
  vector<bool> mask(s.size());

  for(int i = 0; i<s.size(); i++){
    int pos=i;
    vector<int> cad;

    while(pos>=0 and cad.size()!= t.size()){
      if(!mask[pos]){
        if(s[pos] != t[t.size() - cad.size() -1]) break;
        cad.push_back(pos);
      }

      pos--;
    }

    if(cad.size()== t.size())
      for(auto x: cad) mask[x] =true;
  }
  
  for(int i =0; i<s.size(); i++) 
    if(!mask[i]) cout << s[i];

  cout << endl;
  return 0;
}