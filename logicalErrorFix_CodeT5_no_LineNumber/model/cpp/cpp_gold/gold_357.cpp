#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
int n,temp;
vector<int>ans;
scanf("%d%d",&n,&temp);
ans.push_back(temp);
while(n--){
scanf("%d",&temp);
if(temp>ans.back())ans.push_back(temp);
else *lower_bound(ans.begin(),and.end(),temp)=temp;
}
printf("%d\n",ans.size());
}
