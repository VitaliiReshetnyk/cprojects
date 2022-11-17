#include <vector>
#include <iostream>
//10_11
using namespace std;


typedef struct 
{
    string surname;
    string city;
    string street;
    string building;
    unsigned int flat;
} person;

person input_person()
{
    person a{};
    cout << "Surname: ";
    cin >> a.surname;
    cout << "City: ";
    cin >> a.city;
    cout << "Street: ";
    cin >> a.street;
    cout << "Building N: ";
    cin >> a.building;
    cout << "Flat N: ";
    cin >> a.flat;     
    cout << endl;
    return a;   
}

void print_person(person a)
{
    cout << "Surname: " << a.surname << endl;
    cout << "City: " << a.city << endl;
    cout << "Street: " << a.street << endl;
    cout << "Building N: " << a.building << endl;
    cout << "Flat N: " << a.flat << endl;
}

int findp(const vector <person> a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a.at(i).city != a.at(j).city)
            {
                if ((a.at(i).street == a.at(j).street) && 
                    (a.at(i).building == a.at(j).building) &&
                    (a.at(i).flat == a.at(j).flat))
                {
                    cout << "First person" << endl;
                    print_person(a.at(i));
                    cout << endl;
                    cout << "Second person" << endl;
                    print_person(a.at(j));
                    return 1;
                }
            }
        }
    }
    cout << "Not found" << endl;
    return 0;
}


int main()
{
    vector <person> lst;
    unsigned int n;
    cout << "Input number of peple:";
    cin >> n;
    for (unsigned int i = 0; i < n; i++)
    {
        cout << "Person N" << i + 1 << endl;
        lst.push_back(input_person());
    }
    findp(lst);
}