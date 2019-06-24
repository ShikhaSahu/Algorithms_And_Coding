#include<iostream>
using namespace std;

//structure of a trie node
typedef struct trieNode
{
    bool is_end;
    struct trieNode *child[26];
}trienode;

//function that creates a trienode 
trienode *getnode()
{
    trienode *temp=new trienode;
    temp->is_end=false;
    for(int i=0;i<26;i++)
        temp->child[i]=NULL;
    return temp;
}

//Insert words into already existing trie
void insert(trienode *root,string str)
{
    trienode *temp=root;
    for(int i=0;i<str.size();i++)
    {
        int index=str[i]-'a';
        if(!temp->child[index])
            temp->child[index]=getnode();
        temp=temp->child[index];
    }
    temp->is_end=true;
}

//search a word or prefix in trie
bool search(trienode *root,string key)
{
    trienode *temp=root;
    for(int i=0;i<key.size();i++)
    {
        int index=key[i]-'a';
        if(!temp->child[index])
            return false;
        temp=temp->child[index];
    }
   // return temp!=NULL && temp->is_end==true;     //for full string checking
   return temp!=NULL;       //for prefic checking
}

int main()
{
    int n=5;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    trienode *root=getnode();
    for(int i=0;i<n;i++)
    {
        insert(root,arr[i]);
    }
    search(root, "the")? cout << "Yes\n" :  cout << "No\n"; 
    search(root, "ther")? cout << "Yes\n" : cout << "No\n"; 
    return 0;
}
