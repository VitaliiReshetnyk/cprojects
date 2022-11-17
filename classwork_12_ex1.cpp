#include <iostream>
#include <vector>
//10.5

typedef struct 
{
    unsigned int meters;
    std::string name;
} peak;

peak input_peak()
{
    peak p1{};
    std::cout << "Input name: ";
    std::cin >> p1.name;
    std::cout << "Input highness: ";
    std::cin >> p1.meters;
    return p1;
}
void print_peak(const peak p1)
{
    std::cout << "Name: ";
    std::cout << p1.name << std::endl;
    std::cout << "Highness: ";
    std::cout << p1.meters << std::endl;
}

void input_list(std::vector <peak> *a)
{
    int n;
    std::cout << "Input number of mountains: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Mountain N" << i + 1 << std::endl;
        a->push_back(input_peak());
    }
}

void print_list(const std::vector <peak> a)
{
    int i = 1;
    for (peak p: a)
    {
        std::cout << "Mountain N" << i++ << std::endl;
        print_peak(p);
        std::cout << std::endl;
    }
}

peak highest(const std::vector <peak> a)
{   
    peak b{0,""};
    for (peak p: a)
    {
        if (b.meters < p.meters)
        {
            b = p;
        }
    }
    return b;
}

peak find(const std::vector <peak> a, std::string b)
{   
    for (peak p: a)
    {
        if (p.name == b)
        {
            return p;
        }
    }
    std::cout  << "NOT FOUND!!!" << std::endl;
    return peak{0, ""};
}




int main()
{
    std::vector <peak> list_peaks;
    std::string name1;

    input_list(&list_peaks);
    std::cout << std::endl;
    print_list(list_peaks);
    std::cout << std::endl;

    std::cout << "Highest mountain:" << std::endl;
    print_peak(highest(list_peaks));
    std::cout << std::endl;

    std::cout << "Input name of mountain:" << std::endl;
    std::cin >> name1;
    print_peak(find(list_peaks, name1));
    return 0;
}