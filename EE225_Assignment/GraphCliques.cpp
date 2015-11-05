#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


//enter the Unigraph here
// each bracket represents the connected set of edges
//-----------------------------------
int Graph[][2] ={ {1,2},{1,3},{1,10},{2,3},{2,10},{3,10},{3,4},{4,5},{5,6},
					{5,9},{6,7},{7,8},{7,9},{8,9},{10,9},{1,11},{11,12}};
//vector<int> graph[2] =
//-----------------------------------


void dispVector(vector<int> v)
{
	cout<<"Vector("<<v.size()<<") : ";
	cout<<"("<<v[0];
	for(int i =1;i<v.size();i++)
	{
		cout<<","<<v[i];
	}
	cout<<")";
}


int getNumberOfEdges()
{
	return sizeof(Graph)/sizeof(int)/2;
}
int getNumberOfNodes()
{
	int nE = getNumberOfEdges();
	int maxNum = 0;
	for(int i=0;i<nE;i++)
	{
		if(Graph[i][0]>maxNum)maxNum=Graph[i][0];
		if(Graph[i][1]>maxNum)maxNum=Graph[i][1];
	}
	return maxNum;
}
bool checkIfConnected(int node1, int node2)
{
	int nE = getNumberOfEdges();
	for(int i=0;i<nE;i++)
	{
		if(Graph[i][0]==node1)if(Graph[i][1]==node2)return true;
		if(Graph[i][1]==node1)if(Graph[i][0]==node2)return true;
	}
	return false;
}

vector<int> getAdjacentNodes(int initialNode)
{
	vector<int> adjacentNodes;
	int nE = getNumberOfEdges();
	for(int i=0;i<nE;i++)
	{
		if(Graph[i][0]==initialNode)adjacentNodes.push_back(Graph[i][1]);
		else if (Graph[i][1]==initialNode)adjacentNodes.push_back(Graph[i][0]);
	}
	return adjacentNodes;	//  returns adjacent Nodes
}
bool checkIfClique(vector<int> nodes)
{
	for(int i=0;i<nodes.size()-1;i++)
	{
		for(int j=i+1;j<nodes.size();j++)
		{
			if(!checkIfConnected(nodes[i],nodes[j]))return false;
		}
	}
	return true;
}
void getClique(int node)		// prints the clicque at the corresponding node
{
	
	vector<int> adjNodes = getAdjacentNodes(node);
	adjNodes.push_back(node); 	// also add the original node
	if(adjNodes.size()<3)// all cliques less than 3 nodes are either edges or nodes itself
	{	
		cout<<"\n\r\t Edge Clique";
		return;
	}
	//brute Force 
	int N = adjNodes.size();
	bool foundClique = false;
	vector<bool> v(N);
	vector<int> testNodes;
	for(int choose=1;choose<=N;choose++)
	{
		foundClique=false;
		fill(v.begin() +N- choose, v.end(), true);	
		testNodes.clear();	
		do {
			for(int i=0; i<N; i++)
			{
			if(v[i])testNodes.push_back(adjNodes[i]);
			}
		} while ( next_permutation(v.begin(), v.end()));
	
		if(checkIfClique(testNodes))
		{
			sort(testNodes.begin(),testNodes.end());
			cout<<"\n\r\t*Clique at : ";dispVector(testNodes);
			foundClique = true;
		}
		
	}
	if(foundClique==false)
	{
		cout <<"\n\r\tNo Clique with 3 or more nodes found here " <<endl;
	}
}
int main()
{
	for(int i=1;i<=getNumberOfNodes();i++)
	{
		cout<<"\n\rAt node("<<i<<")  ";
		getClique(i);	
	}
}
