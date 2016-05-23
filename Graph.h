#ifndef GRAPH__H
#define GRAPH__H
#include <cstring>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
#include "pqueue.cpp"

using namespace std;
class node;

class edge
{
	public:
		edge() {
			Origin = NULL;
			Dest = NULL;
			weight = 0;
		};
		edge(node* a, node* b, float c): Origin(a), Dest(b), weight(c){};
		node* Origin;
		node* Dest;
		float weight;	
		friend bool operator < (edge a, edge b)
        {
            if(a.weight < b.weight)
                return true;
            else
                return false;
        }
		friend bool operator == (edge a, edge b)
        {
            if(a.weight == b.weight)
                return true;
            else
                return false;
        }
		friend bool operator > (edge a, edge b)
        {
            if(a.weight > b.weight)
                return true;
            else
                return false;
        }
};
class node
{
	public:
		node(string s, float b, float c): name(s), x(b), y(c) {
			visit = 0;
		};
		int visit; // flag to check if the node has been already visited
		float dist;
		string name;
		node* prev;
        int rank;
		
		float x,y; // coordinates of node
		vector<edge> edges; // edges connected to node
		friend bool operator < (node a, node b)
        {
            if(a.dist < b.dist)
                return true;
            else
                return false;
        }
		friend bool operator == (node a, node b)
        {
            if(a.dist == b.dist)
                return true;
            else
                return false;
        }
		friend bool operator > (node a, node b)
        {
            if(a.dist > b.dist)
                return true;
            else
                return false;
        }
};

class DSU
{
    public:
    int *parents;
    DSU(int n)
    {
        parents = new int[n];
        for(int i=0; i < n; i++)
        {
            parents[i] = i;
        }
    }
    void merge(int a, int b);
    int find(int a);
};
class Graph
{
	public:
		vector<node*> Mst; // minimum spanning tree
		vector<node*> cities;
		vector<edge> arcs;
		Graph(char*);
		vector<node*> Kruskal(); //runs kruskal algorithm and returns the Minimum spanning tree
};

#endif

