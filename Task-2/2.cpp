#include <iostream>
#include <cmath>
using namespace std;

void equation()
{
    float A, B, C;
    cout << "Введіть три значення : " << endl;
    cin >> A >> B >> C;

    float discriminant = B * B - 4 * A * C;
    //^--- обчислення дискримінанта

    if (discriminant > 0)
    {

        float x1 = (-B + sqrt(discriminant)) / (2 * A);
        float x2 = (-B - sqrt(discriminant)) / (2 * A);
        cout << x1 << " " << x2 << endl;
        //^--- Два різних дійсних корені
    }
    else if (discriminant == 0)
    {

        float x1 = -B / (2 * A);
        cout << x1 << endl;
        //^--- Один дійсний корінь
    }
    else
    {
        cout << "Нема коренів" << endl;
    }
}

int main()
{
    equation();
}