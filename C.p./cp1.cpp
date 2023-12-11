#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;
map<string, vector<string>> all_buses;
vector<string> stop_names;
vector<string> bus_names;
//^--- all_buses - зберігає назву і зупинки маршруту
//     stop_names зберігає назви зупинок,а bus_names назви маршрутів
void DialogWindows()
{
    cout << "=====================================================================================\n";
    cout << "|                        Автобусна зупинка - Меню вибору                            |\n";
    cout << "=====================================================================================\n";
    cout << "|     Варіант     |                            Дія                                  |\n";
    cout << "=====================================================================================\n";
    cout << "|      EXIT-0     | Вихід                                                           |\n";
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "|    NEW_BUS-1    | Створити новий маршрут                                          |\n";
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "| BUSES_FOR_STOP-2| Вивід назв всіх автобусів, які проходять через вказану зупинку  |\n";
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "| STOPS_FOR_BUS-3 | Вивід назв всіх зупинок вказаного автобуса зі списком автобусів,|\n";
    cout << "|                 | на які можна пересісти на кожній із зупинок                     |\n";
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "|   ALL_BUSES-4   | Вивід списку всіх автобусів із зупинками                        |\n";
    cout << "=====================================================================================\n";
}
//^--- функція яка виводить меню з описом команд
void NEW_BUS()
{
    string bus_name, name_stop;
    int stop_count, counter = 1;
again:
    cout << "Введи назву автобуса : ";
    cin >> bus_name;
    if (all_buses.find(bus_name) != all_buses.end())
    //^--- перевірка чи є у ключах map такий рядок
    {
        cout << "Автобус на ім'я " << bus_name << " вже існує!" << endl;
        goto again;
        //^--- якщо є, goto вертає до вводу назви
    }
    else
    {
        bus_names.push_back(bus_name);
        //^--- якщо нема,зберігає у векторі
    }
repeat:
    cout << "Введи число зупинок : ";
    cin >> stop_count;
    if (cin.fail())
    //^--- якщо у вводі сталась помилка
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Введено букву а не цифру!" << endl;
        goto repeat;
        //^--- очищує cin,ігнорує все що в ньому введено і goto вертає назад до вводу
    }
    else if (stop_count <= 0)
    //^--- перевірка на 0 або меньше нуля
    {
        cout << "Неможе бути 0 або меньше нуля зупинок!" << endl;
        goto repeat;
        //^--- також вертає назад якщо істина
    }
    else
    {
        all_buses.insert(make_pair(bus_name, vector<string>(stop_count)));
        //^--- якщо всі if хиба створюється пара з назвою маршруту і вектору задається довжина
    }
    for (size_t i = 0; i < stop_count; i++)
    {
    repeat_name:
        cout << "Введи назву " << counter << " зупинки : ";
        cin >> name_stop;
        if (find(all_buses[bus_name].begin(), all_buses[bus_name].end(), name_stop) != all_buses[bus_name].end())
        //^--- перевірка чи існує така зупинка у map
        {
            cout << "Ця зупинка вже існує!" << endl;
            goto repeat_name;
        }
        else
        {
            all_buses[bus_name].push_back(name_stop);
            stop_names.push_back(name_stop);
            ++counter;
            //^--- у map із заданим ключем та у вектор sto_names зберігаються зупинки
        }
    }
}
void ALL_BUSES()
{
    if (all_buses.empty())
    //^--- якщо map пустий
    {
        cout << "No buses" << endl;
    }
    else
    {
        for (const auto &kv : all_buses)
        {
            cout << "\n===============================\nBus " << kv.first << ": ";
            for (const auto &stop : kv.second)
            {
                cout << stop << " ";
            }
        }
        cout << "\n===============================" << endl;
        //^--- вкладений цикл виводить map
    }
}
void BUSES_FOR_STOP()
{
    string stop_bus;
    short counter = 0;
    if (all_buses.empty())
    //^--- якщо map пустий
    {
        cout << "No buses" << endl;
    }
    else
    {
    repeat:
        cout << "Введи назву зупинки : ";
        cin >> stop_bus;
        if (find(stop_names.begin(), stop_names.end(), stop_bus) == stop_names.end())
        //^--- перевірка вектора на вміст stop_bus
        {
            cout << "No Stop" << endl;
            goto repeat;
        }
        else
        {
            cout << "Проїжджають : ";
            for (const auto &kv : all_buses)
            {
                for (const string &value : kv.second)
                {
                    if (value == stop_bus)
                    {
                        cout << kv.first << " ";
                    }
                }
            }
            cout << endl;
            //^--- вивід певних маршрутів вкладеним циклом
        }
    }
}
void STOPS_FOR_BUS()
{
    if (all_buses.empty())
    //^--- якщо map пустий
    {
        cout << "No buses" << endl;
    }
    else
    {
        string bus_name;
        short counter = 0;
    repeat:
        cout << "Введи назву автобуса : " << endl;
        cin >> bus_name;
        if (find(bus_names.begin(), bus_names.end(), bus_name) == bus_names.end())
        //^--- if шукає у векторі змінну bus_name
        {
            cout << "No bus" << endl;
            goto repeat;
        }
        else
        {
            cout << "\n===============================\nЗупинки автобуса " << bus_name << " : " << endl;
            for (const auto &kv : all_buses[bus_name])
            {
                if (!kv.empty())
                //^--- if щоб не виводилось пусті рядкі
                {
                    bool interchange = false;
                    cout << "Stop " << kv << ": ";
                    //^--- вивід назв зупинок
                    for (const auto &i : all_buses)
                    {
                        for (const string &value : i.second)
                        {
                            if (value == kv)
                            //^--- перевірка для виводу тільки зупинок bus_name
                            {
                                if (i.first != bus_name)
                                //^--- якщо назва автобуса не співпадає
                                //   ____ у вкладеному if виконується пошук назви в map
                                //  /
                                // \/
                                {
                                    if (find(all_buses[bus_name].begin(), all_buses[bus_name].end(), value) != all_buses[bus_name].end())
                                    {
                                        cout << " " << i.first << " ";
                                        interchange = true;
                                        //^--- якщо знайшло вивід автобуса і присвоєння булевій змінній true
                                    }
                                }
                            }
                        }
                    }
                    if (!interchange)
                    //^--- якщо не знайшли інших автобусів крім bus_name
                    {
                        cout << "no interchange";
                    }
                    cout << endl;
                }
            }
        }
    }
}
int main()
{
    short a, Q, counter;
    cout << "Кількість запитів : ";
    cin >> Q;
    cout << endl;
    DialogWindows();
    while (counter < Q)
    {
        cout << "Введить варіант : ";
        cin >> a;
        if (a == 0)
        {
            break;
        }
        else if (a == 1)
        {
            NEW_BUS();
            counter++;
        }
        else if (a == 2)
        {
            BUSES_FOR_STOP();
            counter++;
        }
        else if (a == 3)
        {
            STOPS_FOR_BUS();
            counter++;
        }
        else if (a == 4)
        {
            ALL_BUSES();
            counter++;
        }
        else
        {
            cout << "Error" << endl;
        }
    }
}
