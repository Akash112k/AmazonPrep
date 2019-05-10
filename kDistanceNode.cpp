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


struct node 
{ 
    int data; 
    struct node *left, *right; 
};

node *newnode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

int dfs(node *head,int target,int k,int cd)
{
	if(head==NULL)
		return -1;
	if(cd == k){
		cout<<head->data<<" ";
		return -1;
	}
	if(head->data == target)
	{
		if(head->left)
			dfs(head->left,target,k,1);
		if(head->right)
			dfs(head->right,target,k,1);
		return 1;
	}


	int leftSubtree = dfs(head->left,target,k,-1);
	if(leftSubtree==k){
		cout<<head->data<<" ";
		return k+1;
	}
	if(leftSubtree!=-1)
	{
		dfs(head->right,target,k,leftSubtree+1);
		return leftSubtree+1;
	}
	int rightSubtree = dfs(head->right,target,k,-1);
	if( rightSubtree == k){
		cout<<head->data<<" ";
		return k+1;
	}
	if(rightSubtree!=-1)
	{
		dfs(head->left,target,k,rightSubtree+1);
		return rightSubtree+1;
	}
}

int main() 
{ 
    node * root = newnode(20); 
    root->left = newnode(8); 
    root->right = newnode(22); 
    root->left->left = newnode(4); 
    root->left->right = newnode(12); 
    root->left->right->left = newnode(10); 
    root->left->right->right = newnode(14); 
    node * target = root->left->right; 
    dfs(root, target->data, 4,-1); 
	cout<<endl;
    return 0; 
}