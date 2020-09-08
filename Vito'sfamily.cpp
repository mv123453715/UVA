#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> num;

int main()
{
  int n, k ,d;
  cin>>n;
  while(n--)
  {
    cin>>k;
    num.clear();
    for(int i=0; i<k;i++)
    {
      cin>>d;
      num.push_back(d);
    }
    sort(num.begin(), num.end());
    int mid=num[(k-1)/2];
    int sum=0;
    for(int i=0;i<k;i++)
    {
      sum+=abs(num[i]-mid);
    }
    cout<<sum<<endl;
  }
  return 0;
}
