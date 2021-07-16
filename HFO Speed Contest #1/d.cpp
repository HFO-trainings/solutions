#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>massiv;

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
int raz = 0;
for(int i = 0; i < n - 1; i++)
{
  if(massiv[i + 1] - massiv[i] > 0){raz = massiv[i + 1] - massiv[i];break;}
}
for(int i = 0; i < n - 1; i++)
{
  if(massiv[i + 1] - massiv[i] > 0)raz = __gcd(raz,massiv[i + 1] - massiv[i]);
}
long long ans = 0;
for(int i = 0; i < n - 1; i++)
{
 long long vz = massiv[n - 1] - massiv[i];
 ans += vz / raz;
}

cout << ans << " " << raz << endl;
return 0;
}
