#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, k;
vector<int>massiv;

int main(){
ios_base::sync_with_stdio(0);
cin >> n >> k;
for(int i = 1; i <= n; i++)
{
  int x;
  cin >> x;
  massiv.push_back(x);
}

long long sum = 0;
long long cur = 0;
for(int i = 0; i < k; i++)
{
  cur += massiv[i];
}
sum = cur;
for(int i = k; i < n; i++)
{
  cur -= massiv[i - k];
  cur += massiv[i];
  sum += cur;
}
cout << fixed << setprecision(6) << (double)sum / (n - k + 1) << endl;
return 0;
}
