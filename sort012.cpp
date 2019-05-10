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
	int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int n = sizeof(arr)/sizeof(int);
	
	int op=-1,tp=-1,zp=-1;
	for(int i=0;i<n;i++){

		if(arr[i]==0){

			if(op==-1 && tp==-1){
				zp=i;
			}
			else if(tp!=-1){

				if(op!=-1){
					swap(arr[i],arr[op+1]);
					op++;
					tp++;
					swap(arr[op],arr[zp+1]);
					zp++;
				}
				else{
					swap(arr[i],arr[zp+1]);
					zp++;
					tp++;
				}
			}
			else if(op!=-1){
				swap(arr[i],arr[zp+1]);
				zp++;
				op++;
			}
		}
		if(arr[i]==1){
			if(tp!=-1){
				swap(arr[op+1],arr[i]);
				tp++;
				op++;
			}
			else{
				op=i;
			}
		}
		if(arr[i]==2){
			tp=i;
		}
	}


	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}