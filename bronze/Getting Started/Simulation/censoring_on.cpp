#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // freopen("censor.in", "r", stdin);
  // freopen("censor.out", "w", stdout);
  string s, t;
  cin >> s >> t;

  int beg = 0;
  int m=0;
  vector<int> kept(s.size()+1);
  vector<int> mask(s.size()+1);

  for(int end = 0; end< s.size(); ++end){
    if(s[end] != t[m]){
      beg = end+(m==0);
      kept[end] = m;
      m=0;
    }

    if(s[end] == t[m]){
      m++;

      if(m == t.size()){
        // cout << beg << " " << end << endl;
        mask[beg]++;
        mask[end+1]--;

        if(beg) m = kept[beg];
        else m=0;

        if(m) beg-= m;
        else beg = end;
      }
    }
    // else{
    //   kept[end] = m;
    //   beg = end;
    //   if(m) end--;
    //   m=0;
    // }
  }

  partial_sum(mask.begin(), mask.end(), mask.begin());

  for(int i =0; i<s.size(); i++) {
    // cout << mask[i] << " ";
    if(!mask[i]) cout << s[i];
  }

  cout << endl;
  return 0;
}