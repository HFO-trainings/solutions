#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


int T;

int main(){
ios_base::sync_with_stdio(0);
//This solution is alternative
//Intuitive and according to math rules is obvious that the number of disctinc counts will be small
//As (sum of x * y) = N  ( 1 <= N <= 2*10^5)
//x (1 <= 10^9) is distinc number , y is count of number x. And number of distinc counts of these numbers are small
//Let's store that distinc counts in set and find answer with help of bruteforce
cin >> T;
while(T--)
{
  int n;
  vector<int>massiv,cnt_of_cnt;
  map<int,int>cnt;
  cin >> n;
  cnt_of_cnt.resize(n + 1);
  for(int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    cnt[x]++; //Counting the appearance of number x
  }
  int maxx = 0;
  int count = 0;
  for(auto i: cnt)
  {
    cnt_of_cnt[i.second]++; //Counting the number of number appearances of each value. We will use it for calculating the answer
  }
  set<pair<int,int> >counts;
  for(auto i: cnt)
  {
    counts.insert(make_pair(i.second,cnt_of_cnt[i.second])); //Adding in set all counts
  }
  //Brutefore part
  int ans = INT_MAX;
  for(auto i: counts)
  {
    //Let's keep the count of all numbers as i
    //And find how much number we will delete
    int sum = 0;
    for(auto j: counts)
    {
     if(j.first >= i.first)sum += (j.first - i.first) * j.second; //If count bigger than what we want to keep , we delete the difference multiplying on number of count.
     else sum += j.first * j.second; //If count smaller than what we want to keep , we delete all that numbers (count * number of count)
   }
   ans = min(ans, sum); //Checking the answer 
  }
  cout << ans << endl;

}

return 0;
}
