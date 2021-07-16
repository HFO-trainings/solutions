#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int,int> >massiv;
set<int>points;

int main(){
ios_base::sync_with_stdio(0);
cin >> n;
for(int i = 1; i <= n; i++)
{
  int x, y;
  cin >> x >> y;
  massiv.push_back(make_pair(x,y));
  points.insert(x);
}

sort(massiv.begin(),massiv.end());
//Adding not important points for comfortable binary search
points.insert(-INT_MAX);
points.insert(INT_MAX);

int r = -INT_MAX;
int ans = 0;
for(int i = 0; i < n; i++)
{
  int x = massiv[i].first;
  int y = massiv[i].second;
  ans++;
  if(x - y > r && *(--points.lower_bound(x)) < x - y)r = x;// left side
  else if(x + y > r && (*points.upper_bound(x)) > (x + y))r = x + y; //right side
  else ans--;//center
}
cout << ans << endl;

return 0;
}
