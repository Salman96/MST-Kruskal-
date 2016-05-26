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
    int counter = 0; //sets rank of each node
    while(1)
    {
        string node, x_cor, y_cor;
        myfile >> node;
        if(node == "ARCS")
            break;
        myfile >> x_cor;
        myfile >> y_cor;
        float t2 = stof(x_cor);
        float t3 = stof(y_cor);
        node *temp = new node(node, t2, t3);
        temp->rank = counter;
        counter++;
        cities.push_back(temp);
    }
    while(!myfile.eof())
    {
        string node1, node2, distance;
        myfile >> node1;
        myfile >> node2;
        if(myfile.eof())
            break;
        myfile >> distance;
        
        float weight = stof(distance);
        int a,b;
        for(int i=0; i < cities.size(); i++)
        {
            if(cities[i]->name == st1){
                a = i;
            }
            else if(cities[j]->name == st2)
            {
                b = j;
            }
        }
        
        edge temp(cities[a], cities[b], weight);
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
