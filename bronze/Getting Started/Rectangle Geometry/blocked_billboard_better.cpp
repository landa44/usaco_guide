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

int area(rectangle rec){
  if( rec.p2.x- rec.p1.x < 0 or rec.p2.y - rec.p1.y < 0) return 0;
  return (rec.p2.x- rec.p1.x)*(rec.p2.y - rec.p1.y);
}

bool belongs(rectangle rec, point p){
  return (rec.p1.x <= p.x and p.x <= rec.p2.x and rec.p1.y <= p.y and p.y <= rec.p2.y);
}

bool inside(rectangle r1, rectangle r2){
  return belongs(r1, r2.p1) and belongs(r1, r2.p2);
}

rectangle intersection(rectangle r1, rectangle r2){
  rectangle inter;
  inter.p1.x = max(r1.p1.x, r2.p1.x);
  inter.p1.y = max(r1.p1.y, r2.p1.y);
  inter.p2.x = min(r1.p2.x, r2.p2.x);
  inter.p2.y = min(r1.p2.y, r2.p2.y);
  return inter;
}

int main(){
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<rectangle> recs(3);

  for(auto &rec: recs)
    cin >> rec.p1.x >> rec.p1.y >> rec.p2.x >> rec.p2.y;
  
  rectangle inter1 = intersection( recs[0], recs[2]);
  rectangle inter2 = intersection( recs[1], recs[2]);

  cout << area(recs[0]) + area(recs[1]) - area(inter1) - area(inter2) << '\n';
  return 0;
}