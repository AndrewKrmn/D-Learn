#include <iostream>
using namespace std;
void shop()
{
    float first_price, a_money, x_percent, b_money, y_percent;
    cout << "Введи початкову ціну : " << endl;
    cin >> first_price;
    cout << "Введи N ціну : " << endl;
    cin >> a_money;
    cout << "Введи другу N ціну : " << endl;
    cin >> b_money;
    cout << "Введи знижку : " << endl;
    cin >> x_percent;
    cout << "Введи другу знижку : " << endl;
    cin >> y_percent;
    if (first_price > a_money)
    {
        first_price -= (x_percent * first_price / 100);
        cout << first_price;
    }
    else if (first_price > b_money)
    {
        first_price -= (y_percent * first_price) / 100;
        cout << first_price;
    }
    else
    {
        cout << "Error" << endl;
    }
}
int main()
{
    shop();
}