#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<char, string> code;

struct CreateNode
{

    char node;
    ll frq;
    CreateNode *left, *right;
};

struct comp
{
    operator()(CreateNode *temp1, CreateNode *temp2)
    {
        return temp1->frq > temp2->frq;
    }
};

void PrintTheHuffmanCode(CreateNode *tree, string s)
{
    if(tree->node != '#')
    {
        code[tree->node] = s;
    }
    if(tree->left !=NULL)
    {
        PrintTheHuffmanCode(tree->left, s + "0");
    }
    if(tree->right != NULL)
    {
        PrintTheHuffmanCode(tree->right, s + "1");
    }
}

void huffman(vector<char> data, vector<ll> freq)
{

    priority_queue<CreateNode*, vector<CreateNode*>, comp> minHeap;

    for(int i = 0; i < data.size(); i++)
    {
        CreateNode *a = new CreateNode;
        a->node = data[i];
        a->frq = freq[i];
        a->left = NULL;
        a->right = NULL;

        minHeap.push(a);
    }

    while(minHeap.size() > 1)
    {
        CreateNode *InternalNode = new CreateNode;

        InternalNode->node = '#';

        ll value1 = minHeap.top()->frq;
        InternalNode->left = minHeap.top();
        minHeap.pop();

        ll value2 = minHeap.top()->frq;
        InternalNode->right = minHeap.top();
        minHeap.pop();

        InternalNode->frq = value1 + value2;
        minHeap.push(InternalNode);

    }

    PrintTheHuffmanCode(minHeap.top(), "");

}

int main()
{
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<ll> freq = {45, 13, 12, 16, 9, 5};

    huffman(data, freq);

    for(auto HuffmanCode : code)
    {
        cout << HuffmanCode.first << ": " << HuffmanCode.second << endl;
    }
}
