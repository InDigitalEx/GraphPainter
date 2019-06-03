#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

// CGraph

class CGraph
{
public:
    CGraph(int value);
    ~CGraph();
    bool Set(int y, int x, string val);
    string Get(int y, int x);
    bool Print();
    bool EnableGrid(bool state);
private:
    const int size = 0;
    bool gridState = false;
    string** data = nullptr;
};

CGraph::CGraph(int value) : size(value)
{
    data = new string* [(size*2)+1];
    for(int i = 0; i < (size*2)+1; i++)
    {
        data[i] = new string[(size*2)+1];
    }
}

CGraph::~CGraph()
{
    for(int i = 0; i < size; i++)
    {
        delete[] this->data[i];
    }
    delete[] this->data;
}

bool CGraph::Set(int y, int x, string val)
{
    // Check array bounds
    if((size * -1) > y || y > size || (size * -1) > x || x > size) {
        cout << "CGraph::Set error: " << y << " " << x << endl;
        return false;
    }

    // Set value to array
    this->data[y+size][x+size] = val + " ";

    return true;
}

string CGraph::Get(int y, int x)
{
    // Check array bounds
    if((size * -1) > y || y > size || (size * -1) > x || x > size) {
        cout << "CGraph::Get error: " << y << " " << x << endl;
        return "";
    }

    string value = this->data[y+size][x+size];

    if(value.empty()) {

        if(this->gridState == true)
        {
            if(x == 0 && y == 0) return "+ ";
            else if(x == 0) return "| ";
            else if(y == 0) return  "— ";
        }
        return "  ";
    }
    else
        return value;
}

bool CGraph::Print()
{
    int yMin = (this->size * -1);
    int yMax = this->size + 1;

    int xMin = (this->size * -1);
    int xMax = this->size + 1;

    for(int y = yMax-1; y >= yMin; y--)
    {
        for(int x = xMin; x < xMax; x++)
        {
            cout << this->Get(y, x);
        }
        cout << endl;
    }
    return true;
}

bool CGraph::EnableGrid(bool state)
{
    this->gridState = state;
    return true;
}

#endif // GRAPH_H
