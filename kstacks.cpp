#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define pi pair<int,int>
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TESTS int TCASES;cin>>TCASES;while(TCASES--)
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define asort(v) sort(all(v));
#define rsort(v) asort(v);reverse(all(v));
#define MOD 1000000007
using namespace std;
template<class T>
ostream& operator<<(ostream& os,const vector<T> &v)
{
	for(int it=0;it<v.size();it++)
	{
		os<<v[it]<<" ";
	}
	os<<"\n";
	return os;
}

main()
{
	int n = 10;
	int k=3;
	vector<int> arr(n);//Storing the actual Elements
	vector<int> top(k,-1);//Storing the top index of all stacks
	vector<int> prev(n,-1);//Storing the previous top of the stack 
	int firstFreeLocation = 0;
	while(true)
	{
		cout<<"Top"<<endl;
		cout<<top<<endl;
		cout<<"Prev"<<endl;
		cout<<prev<<endl;
		int sn;
		cout<<"Enter the stack number you want to operate on (0-"<<k-1<<") : ";
		cin>>sn;
		cout<<"1. Push\n2. Pop\n3. Top\n4 Exit\n";
		int type;
		cin>>type;
		switch (type)
		{
			case 1:
			{
				if(firstFreeLocation>=n){
					cout<<"Overflow\n";
					break;
				}
				int e;
				cout<<"Enter the element you want to push : ";
				cin>>e;
				int z = firstFreeLocation;
				if(prev[z]==-1)
					firstFreeLocation = z+1;
				else
					firstFreeLocation = prev[z];
				prev[z] = top[sn];
				top[sn] = z;
				arr[z] = e;
				break;
			}
			case 2:
			{
				if(top[sn]==-1)
				{
					cout<<"Underflow\n";
					break;
				}
				int elem = arr[top[sn]];
				int firstFreeTemp  = firstFreeLocation;
				int topTemp = top[sn];
				top[sn] = prev[top[sn]];
				prev[topTemp] = firstFreeTemp;
				firstFreeLocation = topTemp;
				cout<<"Popped "<<elem<<endl;
				break;
			}
			case 3:
			{
				if(top[sn]==-1)
					cout<<"Underflow\n";
				else
					cout<<arr[top[sn]]<<endl;
			}
		}
	}

}