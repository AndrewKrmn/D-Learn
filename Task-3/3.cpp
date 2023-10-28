#include <iostream>
using namespace std;
void division()
{
    unsigned int A, B;
    cout << "Введіть два числа" << endl;
    cin >> A >> B;
    if (B == 0)
    {
        cout << "Неможливо" << endl;
    }
    else if (0 <= A <= 1'000'000 && 0 <= B <= 1'000'000)
    {

        cout << A / B << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
}
int main()
{
    division();
}