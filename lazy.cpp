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
	tree[t_index]=min(tree[2*t_index],tree[2*t_index+1]);
}

void updatetree(int *arr,int *tree,int *lazy,int start,int end,int t_index,int left,int right,int val){

	if(start>end){
		return;
	}

	if(lazy[t_index]!=0){
		tree[t_index]+=lazy[t_index];
		if(start!=end){
			lazy[2*t_index]+=lazy[t_index];
			lazy[2*t_index+1]+=lazy[t_index];
		}
		lazy[t_index]=0;

	}

	
	if(end<left || start>right){
		return;
	}

	// if its completely inside the range

	if(start>=left && end<=right){
		tree[t_index]+=val;

		if(start!=end){
			lazy[2*t_index]+=val;
			lazy[2*t_index+1]+=val;
		
		}
		return;
	}

	// if its partially inside the range

    int mid=(start+end)/2;
    updatetree(arr,tree,lazy,start,mid,2*t_index,left,right,val);
    updatetree(arr,tree,lazy,mid+1,end,2*t_index+1,left,right,val);

    tree[t_index]=min(tree[2*t_index],tree[2*t_index+1]);
    


}


int querytree(int *arr,int *tree,int *lazy,int start,int end,int t_index,int left,int right){

     if(lazy[t_index]!=0){
     	tree[t_index]+=lazy[t_index];

     	if(start!=end){
     		lazy[2*t_index]+=lazy[t_index];
			lazy[2*t_index+1]+=lazy[t_index];
     	}
     	lazy[t_index]=0;
     }

	//if its completely outside the range

	if(end<left || start>right){
		return INT_MAX;
	}

	// if its completely inside the range

	if(start>=left && end<=right){
		return tree[t_index];
	}

	// if its partially inside the range

    int mid=(start+end)/2;
	return min(querytree(arr,tree,lazy,start,mid,2*t_index,left,right),querytree(arr,tree,lazy,mid+1,end,2*t_index+1,left,right));
}

int main(){
	int n;
	cin>>n;
	int arr[4];
	int tree[12]={0};
	int lazy[12]={0};

	for(int i=0;i<4;i++){
		cin>>arr[i];
	}
    buildtree(arr,tree,0,3,1);

    cout<<"Segment Tree original:\n";
    for(int i=1;i<12;i++){
    	cout<<tree[i]<<"\n";
    }
    cout<<"\n\n";
    updatetree(arr,tree,lazy,0,3,1,0,3,3);
    updatetree(arr,tree,lazy,0,3,1,0,1,2);

    cout<<"Segment Tree:\n";
    for(int i=1;i<12;i++){
    	cout<<tree[i]<<"\n";
    }
    cout<<"\n\n";

    cout<<"Lazy Tree:\n";

    for(int i=1;i<12;i++){
    	cout<<lazy[i]<<"\n";
    }
    // Range Query Example
    cout<<"Range Query:\n";
    cout<<querytree(arr,tree,lazy,0,3,1,2,3)<<"\n";


   

    return 0;
}