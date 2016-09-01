#include <iostream>
using  namespace  std;
int max2(int a,int b){
	return (a>b)?a:b;
}
int max(int*a,int start,int end){
	if(start==end)return a[end];
	return  max2(a[start],max(a,start+1,end));
}
int main(){
	int a[]={10,5,4,78,500,41,2,1};
	cout<<max(a,0,sizeof(a)/sizeof(int)-1);
}
