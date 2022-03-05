#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);
  int n;
  cin>> n;

  vector<vector<int>> field(20*n+2, vector<int>(20*n+2));
  int r = n*10+1;
  int c = n*10+1;
  field[r][c]++;
  
  char dir;
  int steps;

  map<char, pair<int,int>> mmap;
  mmap['N']= {1,0};
  mmap['S']= {-1,0};
  mmap['E']= {0,1};
  mmap['W']= {0,-1};

  int mmin = mod;
  int time = 1;

  for(int i = 0; i<n;++i){ 
    cin >> dir >> steps;

    while(steps--){
      time++;

      r+= mmap[dir].first;
      c+= mmap[dir].second;

      if(field[r][c]  and time - field[r][c] >= 2) 
        mmin= min(mmin, time - field[r][c]);
      
      field[r][c]= time;
    }
  }
  
  
  cout << (mmin!=mod? mmin: -1) << endl;
  return 0;
}