#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>massiv;
vector<int>ans;

int main(){
ios_base::sync_with_stdio(0);
cin >> n;
for(int i = 1; i <= n; i++)
{
  int x;
  cin >> x;
  massiv.push_back(x);
}

sort(massiv.begin(),massiv.end());

vector<int>left;
vector<int>right;

for(int i = 0; i < n; i++)
{
  if(i % 2 == 0)left.push_back(massiv[i]);
  else right.push_back(massiv[i]);
}

reverse(right.begin(),right.end());

vector<int>ans;

for(auto i: left)ans.push_back(i);
for(auto i: right)ans.push_back(i);

for(int i = 0;i < n;i++)cout << ans[i] << " ";

return 0;
}
