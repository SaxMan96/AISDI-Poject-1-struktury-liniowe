#include "graph.h"

using namespace std;

Graph::Graph(): vertices (0),edges (0)
{

}
Graph::Graph(const Graph& other): vertices (other.vertices),edges (other.edges)
{
    for(auto it = other.edgesTab.begin(); it != other.edgesTab.end(); ++it)
        edgesTab.push_back(*it);
    for(auto it = other.degrees.begin(); it != other.degrees.end(); ++it)
        degrees.push_back(*it);
}
Graph::~Graph()
{
    edgesTab.clear();
}

int Graph::load( string filename )
{
    int isWritten = 0;
    ifstream file;
    file.open( filename );
    if ( !file.good() )
    {
        cout << "Plik nie istnieje!"<< endl;
        return 0;
    }
    string line1,line2;

    getline(file, line1, '\n');
    vertices = atoi(line1.c_str());

    while(!file.eof())
    {
        getline(file, line1, ' ');
        getline(file, line2, '\n');
        pair<int,int> temp;
        temp.first  = atoi(line1.c_str());
        temp.second = atoi(line2.c_str());
        if(temp.first > temp.second)
            swap(temp.first,temp.second);
        for(auto it=edgesTab.begin(); it != edgesTab.end();++it)
            if(*it == temp)
                isWritten = 1;
        if(isWritten)
            break;
        edgesTab.push_back(temp);
        ++edges;
    }
    if(edgesTab.size() != edges)
        cout<<"O KURWA"<<endl;
    file.close();
    std::sort(edgesTab.begin(),edgesTab.end());
    setDegrees();
    return 1;
}

void Graph::show()
{
    cout<<"\twierzcholki: "<<vertices<<endl;
    cout<<"\tkrawedzie:   "<<edges<<endl;
    for(int i=0; i<edges;++i)
        cout<<edgesTab[i].first<<" "<<edgesTab[i].second<<endl;
    /*
    cout<<"\tstopnie:"<<endl;
    for(int i=0; i<vertices;++i)
        cout<<i<<" "<<degrees[i]<<endl;
    */
}

void Graph::setDegrees()
{
    degrees.resize(vertices);
    for(int i=0; i<vertices;++i)
        degrees[i]=0;
    for(int i=0; i<edges;++i)
    {
        ++degrees[edgesTab[i].first];
        ++degrees[edgesTab[i].second];
    }
}
void Graph::permutate(vector<int> fun)
{
    for(int i=0; i<edges;++i)
    {
        edgesTab[i].first  = fun[edgesTab[i].first];
        edgesTab[i].second = fun[edgesTab[i].second];
        if(edgesTab[i].first > edgesTab[i].second)
            swap(edgesTab[i].first,edgesTab[i].second);
    }
    std::sort(edgesTab.begin(),edgesTab.end());
}
bool Graph::operator==(const Graph& other) const
{
    for(int i=0; i<edges;++i)
        if(edgesTab[i].first != other.edgesTab[i].first || edgesTab[i].second != other.edgesTab[i].second)
            return false;
    return true;
}
