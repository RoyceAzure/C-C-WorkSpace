#include<iostream>
#include <vector>
using namespace std;

class Node{
    unsigned short v;
    Node *next;
};
int main()
{
    auto i = 14.4;
    cout << i << endl;

    // vector<vector<*Node>> graph
    // vector<vector<int>> graph(10);
    // graph[0].push_back(2);
    // graph[0].push_back(3);
    // cout << graph[0].size()<< endl;
    // cout << graph.capacity()<< endl;
    // cout << graph[0].capacity()<< endl;

    vector<int> row;
    row.assign(10, -1);
    vector<vector<int>> graph;
    graph.assign(10, row);
    graph[0][0] = 1;
    // graph.at(0).at(1) = 2;
    // graph.at(0).at(2) = 3;
    for (auto i = graph[0].begin(); i != graph[0].end(); i++)
        cout << *i << endl;
}