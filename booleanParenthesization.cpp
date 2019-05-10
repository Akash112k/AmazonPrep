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

int solve(string symbols,string operators)
{

	int n = symbols.length();
	vector<vector<int>> dp(n,vector<int>(n,0));
	
	for(int i=0;i<n;i++)
		dp[i][i] = symbols[i] == 'T';
	for(int len = 1;len<n;len++)
	{
		for(int i=0;i<n;i++)
		{
			int j = i+len;
			if(j>=n)
				break;
			for(int k=i;k<j;k++){

				for(int l = 0; l<operators.length();l++)
				{
					if(operators[l] == '&')
					{
						dp[i][j] += dp[i][k]*dp[k+1][j];
					}
					else if(operators[l]=='|')
					{
						int totalCombIK = pow(3,k-i);
						int totalCombKJ = pow(3,j-k-1);
						dp[i][j] += dp[i][k] * dp[k+1][j];
						dp[i][j] += (totalCombIK-dp[i][k]) * dp[k+1][j];
						dp[i][j] += dp[i][k] * (totalCombKJ - dp[k+1][j]);
					}
					else if(operators[l]=='^')
					{
						int totalCombIK = pow(3,k-i);
						int totalCombKJ = pow(3,j-k-1);
						dp[i][j] += (totalCombIK-dp[i][k]) * dp[k+1][j];
						dp[i][j] += dp[i][k] * (totalCombKJ - dp[k+1][j]);
					}

					if(len==2)
						cout<<dp[i][j]<<" "<<i<<" "<<j<<" "<<k<<"\n-----------------------------\n";
				}

			}
		}
	}
	cout<<dp<<endl;
	return dp[0].back();

}


main()
{
	string symbols = "TFT"; 
    string operators = "|&^";
	cout<<solve(symbols,operators)<<endl;
}

/*
T|F|T  2
T&F&T  0
T^F^T  0
T&F|T  2
T^F|T  1     (T^F)|T
T&F^T  2
T^F&T  2
T|F&T  2
T|F^T  1	T|(F^T)
*/