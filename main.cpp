#include <iostream>
#include <math.h>

#include "CGraph.h"

using namespace std;

int mathY(string buffer, int x)
{
    char exp;
    int value;

    // Input "basic" function
    if(!sscanf(buffer.c_str(), "y=x%c%i", &exp, &value)) {
        cout << "Invalid expression" << endl;
        exit(1);
    }

    // Calculate expression
    switch(exp) {
        case '+': {
            x += value;
            break;
        }
        case '-': {
            x -= value;
            break;
        }
        case '*': {
            x *= value;
            break;
        }
        case '/': {
            if(value == 0) {
                cout << "Oh, Can't be diviede by zero" << endl;
                exit(1);
            }
            x /= value;
            break;
        }
        case '^': {
            x *= x;
            break;
        }
        default: {
            cout << "Invalid expression" << endl;
            exit(1);
        }
    }
    return x;
}

int main() {
    // Input array size
    int size = 0;
    string buff;

    cout << "GraphPainter by in_dgtl" << "\n\n";

    cout << "Input size of graph:" << endl;
    cin >> size;
    if(!cin) {
        cout << "Invalid input" << endl;
        exit(1);
    }

    cout << "Input function chart (Example: y=x*2)" << endl;
    cin >> buff;
    if(!cin) {
        cout << "Invalid input" << endl;
        exit(1);
    }

    // Create instance of Graph class
    CGraph* Graph = new CGraph(size);
    Graph->grid(true);

    // Calculate symbols of graph and show this
    string character;
    for(int x = size * -1; x <= size; x++) {
        int y = mathY(buff, x);
        int yLast = mathY(buff, x+1);

        if(y == yLast) character = "—";
        else if(y < yLast) character = "/";
        else if(y > yLast) character = "\\";

        Graph->set(y, x, character);
    }
    Graph->print();
    delete Graph;

	return 0;
}
