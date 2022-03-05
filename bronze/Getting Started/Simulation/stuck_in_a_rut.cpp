#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; 
  cin >> m;

  vector<char> dir(m);
  vector<int> x(m), y(m);

  vector<int> mask(m, mod);

  for(int i =0; i< m; i++) cin >> dir[i] >> x[i] >> y[i];

  vector<pair<int,int>> inter;

  vector<pair<int, pair<int, int>>> seg;

  for(int n =0; n< m; n++){
    if(dir[n] == 'E') continue;

    for(int e = 0; e< m; e++){
      if(dir[e] == 'N') continue;

      if(x[n] >= x[e] and y[n] <= y[e]){
        seg.push_back({y[e] - y[n], {inter.size(), n}});
        seg.push_back({x[n] - x[e], {inter.size(), e}});

        inter.push_back({x[n], y[e]});
      }
    }
  }

  sort(seg.begin(), seg.end());

  map< int, int> mmap;

  for(auto s: seg){
    if(mask[s.second.second] != mod) continue;

    if(mmap.find(s.second.first) == mmap.end())
      mmap[s.second.first]= s.first;
    else
      if(mmap[s.second.first] != s.first)
        mask[s.second.second] = s.first;
  }

  for(int i = 0; i < m; i++)
    if(mask[i] == mod) cout << "Infinity" << "\n";
    else cout << mask[i] << '\n';
  return 0;
}