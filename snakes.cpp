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

int minDiceThrow(vector<int> &moves)
{
	int n = moves.size();

	vector<int> steps(n,INT_MAX);
	steps[n-1] = 0;
	for(int i = n-2;i>=0;i--)
	{
		if(moves[i]!=-1 && moves[i]<i)
			continue;
		else if(moves[i]>i){
			steps[i] = steps[moves[i]];
		}
		for(int j=1;j<=6;j++){
			
			int dest = i+j;
			if(dest>=n)
				break;
			else if(steps[dest]!=INT_MAX)
				steps[i] = min(steps[i],1+steps[dest]);
		}
	}
	return steps[0];
}

main()
{
	vector<int> moves(30,-1);

    moves[2] = 21; 
    moves[4] = 7; 
    moves[10] = 25; 
    moves[19] = 28; 
  
    moves[26] = 0; 
    moves[20] = 8; 
    moves[16] = 3; 
    moves[18] = 6; 

	cout<<"Minimum No of dice throws "<<minDiceThrow(moves)<<endl;

}