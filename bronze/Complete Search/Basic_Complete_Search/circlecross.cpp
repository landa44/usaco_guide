#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;
#define endl '\n';

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);
  vector<bool> open(26);
  string cows;
  cin >> cows;

  int sol =0;
  for(int i = 0; i< 52; i++){
    if(open[cows[i]-'A']){
      for(int j = i-1; i and cows[j]!= cows[i]; j--)
        sol+= open[cows[j]-'A'];
      
      open[cows[i]-'A'] =  false;
    }
    else open[cows[i]-'A'] = true;
  }

  cout << sol << endl;

  return 0;
}