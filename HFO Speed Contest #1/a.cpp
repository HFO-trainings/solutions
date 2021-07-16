#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int>one,two;

int main(){
ios_base::sync_with_stdio(0);
cin >> n;
for(int i = 1; i <= n; i++)
{
  int x;
  cin >> x;
  one.pb(x);
}
cin >> m;
for(int i = 1; i <= m; i++)
{
  int x;
  cin >> x;
  two.pb(x);
}

sort(one.begin(),one.end());
sort(two.begin(),two.end());
int ans = 0;
int p = 0;
//Two pointers part
for(int i = 0; i < n; i++)
{
  while(p < m && one[i] - two[p] > 1)p++;
  if(p!=m && abs(one[i] - two[p]) <= 1){ans++; if(p != m)p++;}

}

cout << ans << endl;
return 0;
}
