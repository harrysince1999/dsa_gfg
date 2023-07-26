//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class cmp{
    public :
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

class Solution
{
	public:
	    void trav(Node* root, vector<string>& ans, string temp)
	    {
	        if(root->left==NULL && root->right==NULL)
	        {
	            ans.push_back(temp);
	            return;
	        }
	        
	        trav(root->left,ans,temp+'0');
	        trav(root->right,ans,temp+'1');
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*,vector<Node*>, cmp> pq;
		    
		    for(int i=0;i<N;i++)
		    {
		        Node* temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size()>1)
		    {
		        Node* a = pq.top();
		        pq.pop();
		        Node* b = pq.top();
		        pq.pop();
		        
		        Node* node = new Node(a->data + b->data);
		        node->left = a;
		        node->right = b;
		        
		        pq.push(node);
		    }
		    
		    Node* root = pq.top();
		    
		    vector<string> ans;
		    string temp = "";
		    trav(root,ans,temp);
		    
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends