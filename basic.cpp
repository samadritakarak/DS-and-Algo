#include <bits/stdc++.h> 
using namespace std; 
typedef long long LL; 
typedef pair<int, int> pii; 
#define vi vector<int> 
#define vs vector<string> 
#define vpii vector<pii> 
#define all(v) v.begin(), v.end() 
#define fr freopen("input.in","r",stdin) 
#define fw freopen("output.out","w",stdout) 
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++) 
#define forup(i,a,b) for(int i=(a); i<(b); ++i) 
#define fordn(i,a,b) for(int i=(a); i>(b); --i) 
#define rep(i,a) for(int i=0; i<(a); ++i) 
#define gi(x) scanf("%d",&x) 
#define gl(x) cin>>x 
#define gd(x) scanf("%lf",&x) 
#define gs(x) scanf(" %s",x) 
#define F first 
#define S second 
#define pb push_back 
#define pf push_front 
#define mp make_pair 
#define fastio ios::sync_with_stdio(false);cin.tie(NULL); cout << fixed << setprecision(12)
const int inf = numeric_limits<int>::max(); const LL linf = numeric_limits<LL>::max();


void buildtree(int *arr,int *tree,int start,int end,int t_index){
	if(start==end){
		tree[t_index]=arr[start];
		return ;
	}
	int mid=(start+end)/2;
	buildtree(arr,tree,start,mid,2*t_index);
	buildtree(arr,tree,mid+1,end,2*t_index+1);
	tree[t_index]=tree[2*t_index]+tree[2*t_index+1];
}

void updatetree(int *arr,int *tree,int start,int end,int t_index,int idx,int val){
	if(start==end){
		arr[idx]=tree[t_index]=val;
		return;
	}
	int mid=(start+end)/2;

	if(idx>mid){
		updatetree(arr,tree,mid+1,end,2*t_index+1,idx,val);
	}
	else{
		updatetree(arr,tree,start,mid,2*t_index,idx,val);
	}
	tree[t_index]=tree[2*t_index]+tree[2*t_index+1];
}


int querytree(int *arr,int *tree,int start,int end,int t_index,int left,int right){
	//if its completely outside the range

	if(end<left || start>right){
		return 0;
	}

	// if its completely inside the range

	if(start>=left && end<=right){
		return tree[t_index];
	}

	// if its partially inside the range

    int mid=(start+end)/2;
	return (querytree(arr,tree,start,mid,2*t_index,left,right) + querytree(arr,tree,mid+1,end,2*t_index+1,left,right));
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	int tree[2*n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    buildtree(arr,tree,0,n-1,1);
    updatetree(arr,tree,0,n-1,1,2,10);
    for(int i=1;i<2*n;i++){
    	cout<<tree[i]<<"\n";
    }
    cout<<"\n\n";
    cout<<querytree(arr,tree,0,n-1,1,1,3)<<"\n";
    return 0;
}