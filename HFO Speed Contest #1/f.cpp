#include <bits/stdc++.h>

using namespace std;

int f(vector<int>&el)
{
  vector<int>preff;
  int n = (int)el.size();
  preff.resize((int)el.size() + 1);
  preff[n - 1] = el[n - 1];
  for(int i = n - 2; i >= 0; i--)
  {
	 preff[i] = preff[i + 1];
	 preff[i] = max(preff[i], el[i]);
  }
  for(int i = 0;i < n - 1; i++)
  {
    if(el[i] < preff[i + 1])return 1;
  }
  return 0;
}

int n;

int main(){
ios_base::sync_with_stdio(0);
cin >> n;
vector<int>mn,mx;
long long cnt = 0;

for(int i = 1; i <= n;i++)
{
  int nn;
  cin >> nn;
  vector<int>tmp;
  int maxx = 0;
  int minn = INT_MAX;
  for(int j = 1; j <= nn; j++)
  {
	 int x;
	 cin >> x;
	 maxx = max(maxx,x);
	 minn = min(minn,x);
	 tmp.push_back(x);
  }
  int c = f(tmp);
  if(c)cnt++;
  else
  {
	 mn.push_back(minn);
	 mx.push_back(maxx);
  }
}

sort(mn.begin(),mn.end());
sort(mx.begin(),mx.end());

long long ans=0;

for(int i = 0;i < (int)mn.size(); i++)
{
  int ps = upper_bound(mx.begin(), mx.end(), mn[i])-mx.begin();
  int kl = (int)mx.size() - ps;
  ans += (long long)kl;
}

ans += cnt * n + cnt * (n - cnt);
cout << ans << endl;
return 0;
}
