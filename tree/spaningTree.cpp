#include<iostream>
#include <vector>
#include <tuple>
#include<string>
#include <sstream>
#include <algorithm>
#define MAX 9999
using namespace std;

class Node{
    unsigned short v;
    Node *next;
};

tuple<unsigned int, unsigned int> make_tuple(unsigned int n1, unsigned int n2)
{
    tuple<unsigned int, unsigned int> temp(n1, n2);
    return temp;
}


vector<tuple<unsigned int, unsigned int>> make_vector_tuple_fromInput(const string &input)
{
    unsigned short i = 0;
    unsigned int temp1 = MAX, temp2 = MAX;
    
    vector<tuple<unsigned int, unsigned int>> result;
    result.reserve(20);

    for  (char c : input)
    {
        if(isdigit(c))
        {
            // cout << "is digital " << c  << " trans " << c -'0'<< endl;
            if(temp1 != MAX)
                temp2 = c - '0';
            else
                temp1 = c - '0';
            i++;
        }
        if(i % 2 == 0 & i!= 0)
        {
            cout << temp1 <<" store temp "<< temp2<<endl;
            result.push_back(tuple(temp1, temp2));
            i = 0;
            temp1 = temp2 = MAX;
        }
    }
    return result;
}

bool compare_tuple(const tuple<unsigned int, unsigned int> & t1, const tuple<unsigned int, unsigned int> & t2)
{
    return get<0>(t1) < get<0>(t2);
}
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
    // vector<tuple<unsigned int, unsigned int>> rowt;
    // rowt.assign(20, tuple(1, 1));
    // vector<vector<tuple<unsigned int, unsigned int>>> result;
    // result.assign(20, rowt);
    // for (auto i = graph[0].begin(); i != graph[0].end(); i++)
    //     cout << *i << endl;

    // cout << "test tuple " << get<0>(make_tuple(1, 2)) << endl;
    // cout << "test tuple " << get<1>(make_tuple(1, 2)) << endl;

    // cout << "test tuple " << get<0>(result[0][0])<< endl;

    vector<tuple<unsigned int, unsigned int>> result = make_vector_tuple_fromInput("(1,0) (2,3) (5,6) (1,4)");
    for (tuple<unsigned int, unsigned int> temp : result)
    {
        cout << get<0>(temp) <<"  "<<get<1>(temp)<<endl;
    }
    sort(result.begin(), result.end(), compare_tuple);
    for (tuple<unsigned int, unsigned int> temp : result)
    {
        cout << get<0>(temp) <<"  "<<get<1>(temp)<<endl;
    }
    return 0;
}