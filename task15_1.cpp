#include <fstream>
#include <iostream>
#include <cmath>
#include <exception>
//15.1



class WrongRatioException : public std::exception
{
    int nom;
    public:
    WrongRatioException(){}
    WrongRatioException(int x)
    {
        nom = x;
    }
    void show()
    {
        std::cerr << "Ratio Exception\n" << nom << "\n";
    }
};

class Rational
{
    private:
    int nom;
    unsigned denom;

    public:
    Rational()
    {
        nom = 1;
        denom = 1U;
    }
    Rational(int x, unsigned y):nom(x),denom(y)
    {
        if (denom == 0) throw WrongRatioException();
        reduce();
    }

    void show();
    int input();

    int setNom(int x)
    {
        nom = x;
        return 0;
    }

    int setDenom(unsigned y)
    {
        if (y != 0){
            denom = y;
            return 0;
        }
        throw WrongRatioException();
        return -1;
    }

    Rational add(const Rational& x);
    Rational mult(const Rational& x);

    Rational operator+(const Rational& x)
    {
        return add(x);
    }

    Rational operator*(const Rational& x)
    {
        return mult(x);
    }

    Rational operator-(const Rational& x)
    {
        int ch = static_cast<int>(x.denom * nom - x.nom *denom);
        unsigned zn = x.denom * denom;
        return Rational(ch, zn);
    }

    Rational operator/(const Rational& x)
    {
        int ch = static_cast<int>(x.denom * nom);
        unsigned zn = x.denom * nom;
        return Rational(ch, zn);
    }

    Rational operator-()
    {
        return Rational(-nom, denom);
    }

    bool less(const Rational& x)
    {
        return (nom*x.denom < denom*x.nom);
    }

    bool compare(double z)
    {
        return fabs(z - (nom+0.)/denom);
    }

    bool operator<(const Rational& x)
    {
        return less(x);
    }

    bool operator==(const Rational& x)
    {
        return (nom*x.denom == denom*x.nom);
    }

    bool operator!=(const Rational& x)
    {
        return (nom*x.denom != denom*x.nom);
    }

    bool operator<(const double x)
    {
        return fabs(x - static_cast<double>(nom)/denom);
    }

    static unsigned gcd(unsigned x, unsigned y);

    friend void writeToFile(std::string fname, const Rational& r);

    private:
    void reduce();
};

void Rational::show()
{
    std::cout << nom << "/" << denom << "\n";
}

int Rational::input()
{
    int ch;
    unsigned zn = 0;
    std::cout << "Input nom: ";
    std::cin >> ch;
    while(!zn)
    {
        std::cout << "Input denom: ";
        std::cin >> zn;
    }
    nom = ch;
    denom = zn;

    reduce();

    return 0;
}

Rational Rational::add(const Rational& x)
{
    int t = (int)(this->nom * x.denom + denom * x.nom);
    unsigned y = x.denom * denom;
    return Rational(t,y);
}

Rational Rational::mult(const Rational& x)
{
    int t = nom * x.nom;
    unsigned y = x.denom * denom;
    return Rational(t,y);
}

unsigned Rational::gcd(unsigned x, unsigned y)
{
    if (y == 0 || x == 0) return x + y;
    if (x >= y) return gcd(x % y, y);
    return gcd(y % x, x);
}

void Rational::reduce()
{
    int nsd;
    if (nom >= 0) nsd = (int) gcd(nom, denom);
    else nsd = (int) gcd(-nom, denom);
    nom /= nsd;
    denom /= nsd;
}

Rational Hregory(double eps)
{
    Rational s;
    int sign = -1;
    for (int i = 2; eps*i*i < 1; i++)
    {
        Rational tmp;
        tmp.setNom(sign);
        sign = -sign;
        tmp.setDenom(i*i);
        //s = s.add(tmp);
        s = s + tmp;
        if (tmp < 1.0 / (i*i)) break;
    }
    return s;
}

void writeToFile(std::string fname, const Rational& r)
{
    try
    {
        std::fstream fl;
        fl.open(fname.c_str(), std::ios::app);

        fl << r.nom << r.denom;
        fl.close();
    }
    catch(...)
    {
        std::cerr << "problems with writing to file";
    }
}

int main()
{
    Rational r1, r2(2, 3), r5;
    r1.input();

    Rational r3 = -r1 + r2;
    Rational r4 = r1 * r2;
    r3.show();
    r4.show();
    unsigned p = Rational::gcd(60,35);
    std::cout<<p;

    int ch;
    unsigned zn;
    std::cin >> ch >> zn;
    r5.setNom(ch);
    try
    {
        r5.setDenom(zn);
    }
    catch(std::exception& e)
    {
        std::cout << "ex";
        WrongRatioException* el = dynamic_cast< WrongRatioException*>(&e);
        el->show();
    }
    
    Rational q = Hregory(0.01);
    q.show();
    std::cout << std::boolalpha << (q < (M_PI * M_PI / 12.0));
}