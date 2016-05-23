#include "Graph.h"

using namespace std;

void DSU::merge(int a, int b)
{
    parents[find(a)] = find(b);
}

int DSU::find(int a)
{
    if(a == parents[a])
        return a;
    else
        return find(parents[a]);
}

Graph::Graph(char* a)
{
    string line;
    string file = string(a);
    ifstream myfile(file.c_str());
    getline(myfile,line);
    int k = 0;
    while(1)
    {
        string st1, st2, st3;
        myfile >> st1;
        if(st1 == "ARCS")
            break;
        myfile >> st2;
        myfile >> st3;
        float t2 = stof(st2);
        float t3 = stof(st3);
        node *temp = new node(st1, t2, t3);
        temp->rank = k;
        k++;
        cities.push_back(temp);
    }
    while(!myfile.eof())
    {
        string st1, st2, st3;
        myfile >> st1;
        myfile >> st2;
        if(myfile.eof())
            break;
        myfile >> st3;
        
        float w3 = stof(st3);
        int a,b;
        for(int i=0; i < cities.size(); i++)
        {
            if(cities[i]->name == st1){
                a = i;
                break;
            }
        }
        for(int j=0; j < cities.size(); j++)
        {
            if(cities[j]->name == st2)
            {
                b = j;
                break;
            }
                
        }
        
        edge temp(cities[a], cities[b], w3);
        arcs.push_back(temp);
        cities[a]->edges.push_back(temp);
        cities[b]->edges.push_back(temp);
        
        //write code to end function
    }
}



vector<node*> Graph::Kruskal()
{
    pqueue<edge>* np = new pqueue <edge>(arcs);
    float sum = 0;
    DSU sets(cities.size());
    for(int i=np->size/2; i >=0; i--)
        np->minheapify(i);
    edge temp;
    vector<edge> store;
    while(store.size() != cities.size()-1)
    {
        temp = np->ExtractMin();
        for(int i=np->size/2; i >=0; i--)
            np->minheapify(i);
        if(sets.find(temp.Origin->rank) != sets.find(temp.Dest->rank))
        {
            sum = sum + temp.weight;
            store.push_back(temp);
            sets.merge(temp.Origin->rank, temp.Dest->rank);
        }
    }
    cout << "The edges are: " << endl;
    for(int i=0; i < store.size(); i++)
    {
        cout << store[i].Origin->name << "----" << store[i].weight << "----" << store[i].Dest->name << endl;
    }
    cout << "Sum of weights is:" << sum << endl;
    Mst.push_back(temp.Origin);
    return Mst;
}
