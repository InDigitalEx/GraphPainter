#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

// CGraph

class CGraph {
public:
    CGraph(int value);
    ~CGraph();
    bool set(int y, int x, std::string val);
    std::string get(int y, int x);
    bool print();
    bool grid(bool state);
private:
    std::string **data_ = nullptr;
    const int size_ = 0;
    int arraySize_;
    bool grid_ = false;
};

CGraph::CGraph(int value) : size_(value)
{
    arraySize_ = (size_ * 2) + 1; // -|-
    try {
        data_ = new std::string* [arraySize_];
        for (int i = 0; i < arraySize_; i++)
        {
            data_[i] = new std::string[arraySize_];
        }
    }
    catch(std::bad_alloc &e) {
        std::cout << "Memory allocation error: " << e.what() << std::endl;
        exit(1);
    }
}

CGraph::~CGraph()
{
    for (int i = 0; i < arraySize_; i++) {
        delete[] data_[i];
    }
    delete[] data_;
}

bool CGraph::set(int y, int x, std::string val)
{
    // Check array bounds
    if((size_ * -1) > y || y > size_ || (size_ * -1) > x || x > size_) {
        return false;
    }

    // Set value to array
    data_[y+size_][x+size_] = val + " ";

    return true;
}

std::string CGraph::get(int y, int x)
{
    // Check array bounds
    if ((size_ * -1) > y || y > size_ || (size_ * -1) > x || x > size_) {
        return "";
    }

    std::string value = data_[y + size_][x + size_];

    if(value.empty()) {

        if(grid_ == true)
        {
            if(x == 0 && y == 0) return "+ ";
            else if(x == 0) return "| ";
            else if(y == 0) return  "— ";
        }
        return "  ";
    }
    else {
        return value;
    }   
}

bool CGraph::print()
{
    int yMin = (size_ * -1);
    int yMax = size_ + 1;

    int xMin = (size_ * -1);
    int xMax = size_ + 1;

    for(int y = yMax-1; y >= yMin; y--) {
        for(int x = xMin; x < xMax; x++) {
            std::cout << this->get(y, x);
        }
        std::cout << std::endl;
    }
    return true;
}

bool CGraph::grid(bool state)
{
    return grid_ = state;
}

#endif // GRAPH_H
