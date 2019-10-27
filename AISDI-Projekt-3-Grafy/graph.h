#ifndef GRAPH
#define GRAPH
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <algorithm>

using namespace std;
class Graph
{
public:
    unsigned int vertices;
    unsigned int edges;
    vector<pair<int,int>> edgesTab;
    vector<int> degrees;

    Graph();
    Graph(const Graph&);
    ~Graph();
    int load(string);
    void show();
    void permutate(vector<int>);
    bool operator==(const Graph&) const;
private:
    void setDegrees();

};
#endif // GRAPH
