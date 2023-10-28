#include <iostream>
#include <string>
using namespace std;
void first_task()
{
    string str = "milk", str1 = "milkshake", str2 = "mounth";
    string str3 = "c", str4 = "a", str5 = "b", str6 = "fire", str7 = "fog", str8 = "wood";
    //^--- змінні
    string min_str1 = str;
    //^--- мінімальна змінна першого рядка
    if (str1 < min_str1)
    {
        min_str1 = str1;
    }
    else if (str2 < min_str1)
    {
        min_str1 = str2;
    }
    cout << min_str1 << endl;
    //^--- вивід результату першого рядка
    string min_str2 = str3;
    //^--- мінімальна змінна другого рядка
    if (str4 < min_str2)
    {
        min_str2 = str4;
    }
    else if (str5 < min_str2)
    {
        min_str2 = str5;
    }
    cout << min_str2 << endl;
    //^--- вивід результату другого рядка
    string min_str3 = str6;
    //^--- мінімальна змінна третього рядка
    if (str7 < min_str3)
    {
        min_str3 = str7;
    }
    else if (str8 < min_str3)
    {
        min_str3 = str8;
    }
    cout << min_str3 << endl;
    //^--- вивід результату третього рядка
}
//^--- функція 1 завдання
int main()
{
    cout << "================1 task================\n";
    first_task();
    //^--- виклик функції першого завдання
    return 0;
}