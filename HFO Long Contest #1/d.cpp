#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<int>weeks;

int main(){
ios_base::sync_with_stdio(0);
//Main idea:
//It is obvious to see that we need to delete the full first week in order to find the full middle weeks.
//After finding the count of full middle weeks. We need to find the start date of first week and end date of last week,
//which will give us the maximum answer. As it will be no more than 2-3 weeks, we add that weeks with reserve.
//As count of days it is very small , we can find the first day and last day, which will give us maximum answer by bruteforce in O(days ^ 2);
vector<int>food;
food.resize(3);
for(int i = 0; i < 3; i++)cin>>food[i];
vector<int>food_copy = food;
int food_one_week = 0;
//Adding one week
weeks.push_back(0); //Monday
weeks.push_back(1); //Tuesday
weeks.push_back(2); //Wednesday
weeks.push_back(0); //Thursday
weeks.push_back(2); //Friday
weeks.push_back(1); //Saturday
weeks.push_back(0); //Sunday
int ans;
int sig = 0;
//Deleting the first week food
for(int i = 0; i < 7; i++)
{
  if(food[weeks[i]] == 0)
  {
    sig = 1;
    ans = i;
    break;

  }
  food[weeks[i]]--;
}

int week = 1;
//Finding the full middle weeks
int one = food[0] / 3.0;
int two = food[1] / 2.0;
int three = food[2] / 2.0;

week += min(one,min(two,three));
int ud = min(one,min(two,three));
food[0] = max(food[0] - 3 * ud,0);
food[1] = max(food[1] - 2 * ud,0);
food[2] = max(food[2] - 2 * ud,0);
//

//Adding the first week food back
week--;
if(sig)food = food_copy;
else
{
  food[0] += 3;
  food[1] += 2;
  food[2] += 2;
}
//

//Modulate the process. Finding answer by bruteforce.
int days = week * 7;
ans = max(ans,days);
//Adding 7 weeks
for(int i = 1; i <= 7; i++)
{
  weeks.push_back(0); //Monday
  weeks.push_back(1); //Tuesday
  weeks.push_back(2); //Wednesday
  weeks.push_back(0); //Thursday
  weeks.push_back(2); //Friday
  weeks.push_back(1); //Saturday
  weeks.push_back(0); //Sunday
}
//Modulate the process. Finding answer by bruteforce.
for(int i = 0; i < (int) weeks.size(); i++)
{
  food_copy = food;
  int days_copy = days;
  for(int j = i; j < (int)weeks.size(); j++)
  {
    if(food[weeks[j]] == 0)
    {
      break;
    }
    days++;
    food[weeks[j]]--;
  }
  ans = max(ans,days);
  food = food_copy;
  days = days_copy;
}

cout << ans << endl;

return 0;
}
