struct Node{
	Node* links[2];
	
	bool containKey(int bit){
		return (links[bit]!=NULL);
	}
	Node* get(int bit){
		return links[bit];
	}
	void put(int bit,Node* node){
		links[bit]=node;
	}
};

class Trie{
private:
	Node* root;
public:
	Trie(){
		root=new Node();
	}
public:
	void insert(int num)
	{
		Node* node=root;
		for(int i=31;i>=0;i--)
		{
			int bit=(num>>i)&1;
			if(!node->containKey(bit))
				node->put(bit,new Node());
			
			node=node->get(bit);
		}
	}
public:
	int getMax(int num)
	{
		Node* node=root;
		int mx=0;
		for(int i=31;i>=0;i--)
		{
			int bit=(num >> i) & 1;
			if(node->containKey(1-bit))
			{
				mx=mx | (1 << i);
				node=node->get(1-bit);
			}
			else
			node=node->get(bit);
		}
		return mx;
	}
	
	
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
	for(auto &it:arr1)
		trie.insert(it);
	
	int mx=0;
	for(auto &it:arr2)
	{
		mx=max(mx,trie.getMax(it));
	}
	return mx;
}