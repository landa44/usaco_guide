#include<bits/stdc++.h>

using namespace std;
struct point{
  int x;
  int y;
};

struct rectangle{
  point p1;
  point p2;
};

bool belongs(rectangle rec, point p){
  return (rec.p1.x <= p.x and p.x <= rec.p2.x and rec.p1.y <= p.y and p.y <= rec.p2.y);
}

bool inside(rectangle r1, rectangle r2){
  return belongs(r1, r2.p1) and belongs(r1, r2.p2);
}

int main(){
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<rectangle> recs(3);

  for(auto &rec: recs)
    cin >> rec.p1.x >> rec.p1.y >> rec.p2.x >> rec.p2.y;
  
  int sol= 0;
  for(int i =-1000; i < 1000; i++){
    for( int j = -1000; j < 1000; j++)
    {
      rectangle r;
      r.p1.x = i;
      r.p1.y = j;
      r.p2.x = i+1;
      r.p2.y = j+1;
      if((inside(recs[0],r) or inside(recs[1], r)) and !inside(recs[2], r))
        sol++;
    }
  }

  cout << sol << '\n';
  return 0;
}