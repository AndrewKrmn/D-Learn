#include <iostream>
using namespace std;
int main()
{
    unsigned int A, B;

    cin >> A >> B;
    if (A <= B && A >= 1 && B <= 30000)
    {
        for (size_t i = A; i <= B; i++)
        {
            if (i % 2 == 0)
            {

                cout << " " << i << endl;
            }
        }
    }
}