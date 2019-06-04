#include <iostream>
#include <math.h>

#include "CGraph.h"

using namespace std;

int MathY(string buffer, int x)
{
    char exp;
    int value;

    if(!sscanf(buffer.c_str(), "y=x%c%i", &exp, &value))
    {
        cout << "Invalid expression" << endl;
        exit(1);
    }

    switch(exp)
    {
        case '+':
        {
            x += value;
            break;
        }
        case '-':
        {
            x -= value;
            break;
        }
        case '*':
        {
            x *= value;
            break;
        }
        case '/':
        {
            if(value == 0)
            {
                cout << "Oh, Can't be diviede by zero" << endl;
                cout << "Value set to 1" << endl;
                value = 1;
            }
            x = static_cast<int>(x / value);
            break;
        }\
        case '^':
        {
            x = static_cast<int>(pow(x, value));
            break;
        }
        default:
        {
            cout << "Invalid expression" << endl;
            exit(1);
        }
    }
    return x;
}

int main()
{
    int size = 0;
    int modifer = 0;
    string buff;

    cout << "GraphPainter by in_dgtl" << "\n\n";

    cout << "Input size of graph:" << endl;
    cin >> size;
    if(!cin)
    {
        cout << "Invalid input" << endl;
        exit(1);
    }

    cout << "Input function chart (Example: y=x*2)" << endl;
    cin >> buff;
    if(!cin)
    {
        cout << "Invalid input" << endl;
        exit(1);
    }


    CGraph* Graph = new CGraph(size);
    Graph->EnableGrid(true);

    string character;
    for(int x = size*-1; x <= size; x++)
    {
        int y = MathY(buff, x);
        int yLast = MathY(buff, x+1);

        if(y == yLast) character = "—";
        else if(y < yLast) character = "/";
        else if(y > yLast) character = "\\";

        Graph->Set(y, x, character);
    }

    Graph->Print();

    delete Graph;
	return false;
}
