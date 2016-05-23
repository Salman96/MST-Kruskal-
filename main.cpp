#include "Graph.cpp"
int main()
{
	cout << "Enter Name of File: ";
	char buf[256];
	cin >> buf;
	Graph *g = new Graph(buf);
    cout << "MST FOR THE INPUT FILE IS:" << endl;
    g->Kruskal();
}