#include "Header.h"
#include <fstream>

using namespace std;
template <typename T>

T GetCorrectNumber(T min, T max)
{
    T x;
    while ((cin >> x).fail() || x < min || x > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Type number (" << min << "-" << max << "):";
    }
    return x;
}

template <typename T>
T GetCorrectNumber(T min)
{
    T x;
    while ((cin >> x).fail() || x < min)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Type number (0...): ";
    }
    return x;
}

void print_pipe(Pipe& pipe)
{
    cout << "Information about pipe: " << endl
        << "\tId: " << pipe.id
        << "\tLength: " << pipe.length
        << "\tDiameter: " << pipe.diameter << endl;
}

Pipe input_pipe()
{

    Pipe pipe;
    pipe.id = 0;
    cout << "Please, enter the information about pipe " << endl;
    cout << "Enter the length: ";
    pipe.length = GetCorrectNumber(0);
    cout << "Enter the diameter: ";
    pipe.diameter = GetCorrectNumber(0);
    return pipe;
}

Pipe load_pipe()
{
    ifstream fin;
    fin.open("data.txt", ios::in);
    double b[3]; int i = 0;
    Pipe pipe;
    if (fin.is_open()) {
        while (!fin.eof()) {
            if (fin >> b[i])
            {
                i = i + 1;
            }
            else
            {
                fin.clear();
                fin.ignore(1, ' ');
            }
        }
        pipe.id = b[0];
        pipe.length = b[1];
        pipe.diameter = b[2];
    }
        fin.close();
        return pipe;
    
}

Station load_station()
{
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open()) {
        Station station;
        fin >> station.id;
        fin >> station.name;
        fin >> station.num;
        fin >> station.num_process;
        fin >> station.eff;
        fin.close();
        return station;
    }
}

Station input_station()
{
    Station station;
    station.id = 0;
    cout << "Please, enter the information about station " << endl;
    cout << "Enter the name: ";
    cin >> station.name;
    cout << "Enter the number of factories: ";
    cin >> station.num;
    cout << "Enter the number of factories in process: ";
    station.num_process = GetCorrectNumber(0, station.num);
    cout << "Enter the efficiency: ";
    station.eff = GetCorrectNumber(0, 100);
    return station;
}

void print_station(Station& station)
{
    cout << "Information about station: " << endl
        << "\tId: " << station.id
        << "\tName: " << station.name << endl
        << "\tNumber of factories: " << station.num << endl
        << "\tNumber of factories in process: " << station.num_process << endl
        << "\tEfficiency: " << station.eff << endl;
}

void print_menu()
{
    cout << " Menu " << endl
        << "1. Add pipe" << endl
        << "2. Add station" << endl
        << "3. Edit pipe" << endl
        << "4. Edit station" << endl
        << "5. Save pipe" << endl
        << "6. Save station" << endl
        << "7. Download pipe" << endl
        << "8. Download station" << endl
        << "0. Exit" << endl;
}

void edit_pipe(Pipe& pipe)
{
    cout << "Please, enter the information about pipe " << endl;
    cout << "Enter the length: ";
    cin >> pipe.length;
    cout << "Enter the diameter: ";
    cin >> pipe.diameter;
}

void edit_station(Station& station)
{
    cout << "Please, enter the information about station " << endl;
    cout << "Please, enter the information about station " << endl;
    cout << "Enter the name: ";
    cin >> station.name;
    cout << "Enter the number of factories: ";
    cin >> station.num;
    cout << "Enter the number of factories in process: ";
    cin >> station.num_process;
    cout << "Enter the efficiency: ";
    cin >> station.eff;
}

void save_pipe(Pipe& pipe)
{
    ofstream fout;
    fout.open("data.txt", ios::out);
    if (fout.is_open()) {
        fout << "id: " << pipe.id << endl
            << "length: " << pipe.length << endl
            << "diameter: " << pipe.diameter << endl;
        fout.close();
    }

}

void save_station(Station& station)
{
    ofstream fout;
    fout.open("data.txt", ios::out);
    if (fout.is_open()) {
        fout << station.id << endl
            << station.name << endl
            << station.num << endl
            << station.num_process << endl
            << station.eff << endl;
        fout.close();
    }
}


int main()
{
    Pipe pipe;
    Station station;
    while (1)
    {
        print_menu();
        switch (GetCorrectNumber(0, 8))
        {
        case 1:
        {
            pipe = input_pipe();
            break;
        }
        case 2:
        {
            station = input_station();
            break;
        }
        case 3:
        {
            edit_pipe(pipe);
            break;
        }
        case 4:
        {
            edit_station(station);
            break;
        }
        case 5:
        {
            save_pipe(pipe);
            break;
        }
        case 6:
        {
            save_station(station);
            break;
        }

        case 7:
        {

            pipe = load_pipe();
            print_pipe(pipe);
            break;
        }

        case 8:
        {
            station = load_station();
            print_station(station);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "Wrong action" << endl;
        }
        }
    }

    return 0;
}