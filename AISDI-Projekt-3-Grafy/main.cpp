
#include "graph.h"

using namespace std;
void izomorfic(Graph g1, Graph g2)
{
    if(g1.vertices != g2.vertices){
        cout<<"Nieizomorficzne1\n";
        return;
    }
    if(g1.edges != g2.edges){
        cout<<"Nieizomorficzne2\n";
        return;
    }
    vector<int> d1 = g1.degrees;
    vector<int> d2 = g2.degrees;
    sort(d1.begin(),d1.end());
    sort(d2.begin(),d2.end());
    for(unsigned int i=0;i<g1.vertices;++i)
        if(d1[i] != d2[i]){
            cout<<"Nieizomorficzne3\n";
            return;
        }
    vector<int> fun;
    for(unsigned int i=0;i<g1.vertices;++i)
        fun.push_back(i);
    Graph temp;
    do
    {
        temp = g1;
        temp.permutate(fun);
        if(temp == g2)
        {
            cout<<"Izomorficzne"<<endl;
            for(unsigned int i=0; i<temp.vertices;++i)
                cout<<i<<" --> "<<fun[i]<<endl;
            return;
        }
    }
    while ( std::next_permutation(fun.begin(),fun.end()));
    cout<<"Nieizomorficzne4\n";
    return;
}
int main(int argc, char *argv[])
{
	Graph graph1;
	Graph graph2;

	if(argc < 3)
	{
        cout<<"Podaj dwa argumenty"<<endl;
        return 1;
	}
    /*
	graph1.load("graf1.txt");
	graph1.show();
	graph2.load("graf2.txt");
	graph2.show();
	izomorfic(graph1,graph2);
    */
	if( graph1.load(argv[1]) && graph2.load(argv[2]) )
        izomorfic(graph1,graph2);
	else
        return 1;
	return 0;
}
