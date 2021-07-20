#include <bits/stdc++.h>

using namespace std;

vector<int>preff;

int main(){
ios_base::sync_with_stdio(0);

preff.push_back(0);
int n;
cin >> n;
for(int i = 1; i <= n; i++)
{
  int x;
  cin >> x;
  int sum = preff.back() + x;
  preff.push_back(sum);
}

int q;
cin >> q;
while(q--)
{
  int x;
  cin >> x;
  cout<<lower_bound(preff.begin(),preff.end(),x) - preff.begin()<<endl;
}

return 0;
}
