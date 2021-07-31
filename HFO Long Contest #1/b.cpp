#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string stroka;

int main(){
ios_base::sync_with_stdio(0);
cin >> stroka;
int sig = 0;
sig = (stroka[0] == '-' ? 1 : 0);
if((int)stroka.size() > 19 + sig)
{
  cout << "BigInteger" << endl;
  return 0;
}

if((int)stroka.size() == 19 + sig)
{
  string limit;
  if(sig)limit = to_string(LLONG_MIN);
  else limit = to_string(LLONG_MAX);
  if(stroka > limit){cout <<"BigInteger" << endl; return 0;}
}

long long x = stoll(stroka);
if(x >= -128 && x <= 127)cout << "byte" << endl;
else if(x >= -32768 && x <= 32767)cout << "short" << endl;
else if(x >= INT_MIN && x <= INT_MAX)cout << "int" << endl;
else if(x >= LLONG_MIN && x <= LLONG_MAX)cout << "long" << endl;

return 0;
}
