#include <iostream>
#include <string>
using namespace std;
int main()
{
    string f;
    cin >> f;
    auto index = f.find('f');
    if (index == string::npos)
    {
        cout << -2 << endl;
    }
    else
    {
        auto second_index = f.find('f', index + 1);
        if (second_index == string::npos)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << second_index << endl;
        }
    }
}