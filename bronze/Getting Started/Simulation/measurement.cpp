#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  map<string,int> mmap;
  mmap["Bessie"] = 0;
  mmap["Elsie"] = 1;
  mmap["Mildred"] = 2;

  int n;
  cin >> n;

  vector<pair<int, pair<int,int>> > enter(n);
  vector<int> farm(3,7);

  for(int i =0; i< n; ++i){
    int a, b;
    string name;
    cin >> a >> name >> b;
    enter[i] =  {a,{b,mmap[name]}};
  }

  sort(enter.begin(), enter.end());

  set<int> best;
  int sol = 0;

  for(int i = 0; i< n; i++){
    farm[enter[i].second.second] += enter[i].second.first;
    
    int mmax = *max_element(farm.begin(), farm.end());
    set<int> curr;
    
    for(int j = 0; j<3;++j)
      if(farm[j] == mmax) curr.insert(j);
    
    if(curr!=best) 
      sol++;
    
    best = curr;
  }

  cout << sol << endl;
  return 0;
}