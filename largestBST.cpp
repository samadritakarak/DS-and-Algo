#include<bits/stdc++.h>
using namespace std;
#define maxx 100
int preorder[maxx];//= {1,2,3,4,8,5,6,7};
int inorder[maxx];//= {3,2,8,4,1,6,7,5};
int m,n;//=8;
class node
{
public:
    int data;
    node *left,*right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};
int i=0;
node* create(int s,int e)
{
    if(s>e)
        return NULL;
    node* root = new node(preorder[i]);
    int idx=-1;
    for(int j=s; j<=e; j++)
        if(inorder[j]==preorder[i])
        {
            idx=j;
            break;
        }
    i++;
    root->left = create(s,idx-1);
    root->right = create(idx+1,e);

    return root;
}
int sizeTree(node* root)
{
    if(root==NULL)
        return 0;
    return sizeTree(root->left)+1+sizeTree(root->right);
}
bool isBst(node* root,int minV=INT_MIN,int maxV=INT_MAX)
{
    if(root==NULL)
        return true;
    if(root->data>=minV && root->data<=maxV && isBst(root->right,root->data,maxV) && isBst(root->left,minV,root->data))
        return true;
    return false;
}
int large(node* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    if(isBst(root))
    {
        return sizeTree(root);
    }
    return max(large(root->left),large(root->right));
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>preorder[i];
    //cin>>m;
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    node* root = create(0,n-1);
    //cout<<"***";
    cout<<large(root);
}
