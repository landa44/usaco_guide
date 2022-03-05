#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("guess.in", "r", stdin);
  // freopen("guess.out", "w", stdout);
  int n;
  cin >> n;

  vector<set<string>> characteristics(n);

  for(int i = 0; i< n; i++){
    string animal;
    cin>> animal;

    int m;
    cin >> m;

    while(m--){
      string c;
      cin >> c;

      characteristics[i].insert(c);
    }
  }

  int sol = 0;
  for(int i = 0; i< n; i++){

    for(int j = 0; j < n; j++){
      if(i==j) continue;

      int candidate = 1;  
      for(auto x: characteristics[i]) 
        if(characteristics[j].count(x)) candidate++;
      
      sol = max(sol, candidate);
    }
  }


  cout << sol << endl;
  return 0;
}