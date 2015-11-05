#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void dispVector(vector<bool> v)
{
	cout<<endl<<"Vector("<<v.size()<<") ";
	for(int i =0;i<v.size();i++)
	{
		cout<<":"<<v[i];
	}
}
int main() {
    int n=4, r=5;
     

     vector<bool> v(n);
     fill(v.begin() + n - r, v.end(), true);

    do {
      dispVector(v);
    } while ( next_permutation(v.begin(), v.end()));
    return 0;
}
