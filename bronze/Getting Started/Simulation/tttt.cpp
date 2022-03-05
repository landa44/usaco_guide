#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  vector<string> table(3);
  vector<set<char>> candidates(8);


  for(auto &x: table) cin >> x;

  for(int i = 0; i< 3; i++){
    for(int j = 0; j< 3; j++){
      candidates[i].insert(table[i][j]);
      candidates[3+j].insert(table[i][j]);
      if(i==j) candidates[6].insert(table[i][j]);
      if(i+j == 2) candidates[6+1].insert(table[i][j]);
    }
  }


  int ind =0;
  int team = 0;
  map<set<char>, int> mask;
  for(auto x: candidates){
    if(!mask[x]){
      if(x.size() == 1) ind++;
      if(x.size() == 2) team++;
    }
    mask[x]++;
  }

  cout << ind << endl << team << endl;
  return 0;
}