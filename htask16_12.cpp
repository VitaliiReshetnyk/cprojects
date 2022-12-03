#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//16_12

class equation
{
    protected:
    double start;
    double end;
    double coef_a;
    double coef_b;
    double eps;
    double root;
    double not_work = 0;
    public:
    void set_a(double a_)
    {
        coef_a = a_;
    }
    void set_b(double b_)
    {
        coef_b = b_;
    }
    void set_eps(double eps_)
    {
        eps = eps_;
    }

    double get_a()
    {
        return coef_a;
    }
    double get_b()
    {
        return coef_b;
    }
    double get_eps()
    {
        return eps;
    }
    double get_root()
    {
        return root; 
    }
    double get_not_work()
    {
        return not_work; 
    }
    double count(double x){}
    void show();
    int sign(double x)
    {
        if (x>0)  return 1;
        if (x<0)  return -1;
        return 0;
    }


    void set_start(double strt)
    {
        start = strt;
    }
    void set_end(double nd)
    {
        end = nd;
    }

    double get_start()
    {
        return start;
    }
    double get_end()
    {
        return end;
    }


    int solve()
    {
        not_work = 0;
        double c, fa = count(start), fb = count(end), fc; 
        int number = 0;
        if( abs(fa) < eps )
        {
            root = start;
        }
        if( abs(fb) < eps ) 
        {
            root = end;
        }
        if(sign(fa) == sign(fb)) 
        {
            not_work = 1;
            cout << "Problem" << endl;
            return -1;
        }
        double b = end;
        double a = start;
        for(; fabs(b - a) >= eps; number++)
        {
            c = (a + b) / 2;
            fc = count(c);
            if (fc == 0)
            {
                root = c;
                return 0;
            }

            if (sign(fc) == sign(fa))
            { 
                a = c; 
            } 
            else 
            { 
                b = c;
            }
        }
        root = c;
        return 0;
    }
};


class Linear : public equation
{
    public:
    Linear(double aa, double bb, double startt, double endd, double epss=0.001)
    {
        coef_a = aa;
        coef_b = bb;
        start = startt;
        end = endd;
        eps = epss;
    }
    void show()
    {
        cout << coef_a << "x" << "=" << coef_b << endl;
    }
    double count(double x)
    {
        return coef_a*x-coef_b;
    }
};

class cubic : public equation
{
    protected:
    double coef_c;
    double coef_d;
    public:
    cubic(double aa, double bb, double cc, double dd, double startt, double endd, double epss=0.001)
    {
        coef_a = aa;
        coef_b = bb;
        coef_c = cc;
        coef_d = dd;        
        start = startt;
        end = endd;
        eps = epss;
    }
    void set_c(double c_)
    {
        coef_c = c_;
    }
    void set_d(double d_)
    {
        coef_d = d_;
    }
    double get_c()
    {
        return coef_c;
    }
    double get_d()
    {
        return coef_d;
    }
    void show()
    {
        cout << "(" << coef_a << ")x^3" << "+(" << coef_b << ")x^2+(" << coef_c << ")x+(" << coef_d << ")" << endl;
    }
    double count(double x)
    {
        return coef_a*x*x*x+coef_b*x*x+coef_c*x+coef_d;
    }
};

class sinus : public equation
{
    public:
    sinus(double aa, double bb, double startt, double endd, double epss=0.001)
    {
        coef_a = aa;
        coef_b = bb;
        start = startt;
        end = endd;
        eps = epss;
    }
    void show()
    {
        cout << "sin(" << coef_a << "x)=" << coef_b <<endl;
    }
    double count (double x)
    {
        return sin(x*coef_a) - coef_b;
    }
};

class exponential: public equation
{
    public:
    exponential(double aa, double bb, double startt, double endd, double epss=0.001)
    {
        coef_a = aa;
        coef_b = bb;
        start = startt;
        end = endd;
        eps = epss;
    }
    void show()
    {
        cout << "e^(" << coef_a << "x)=" << coef_b << endl;
    }    
    double count (double x)
    {
        return exp(coef_a*x)-coef_b;
    }
};


int main()
{
    double biggest;
    double abs_start;
    double abs_end;
    double sum;
    vector <Linear> lin_list = {Linear (2, 10, 4, 6),
                                Linear (2, 20, 4, 6), 
                                Linear (1, 50, 49, 50.1), 
                                Linear (3, 48, 10, 18)};
    vector <sinus> sin_list =  {sinus (2, 0.5, -3, 3),
                                sinus (2, 20, -4, 6), 
                                sinus (1, 0.5, -4, 9), 
                                sinus (3, 0.45, 0, 1)};
    vector <exponential> exp_list =  
                               {exponential (4, 40, -3, 3),
                                exponential (6, 29, -4, 6), 
                                exponential (7, 1096, -4, 0), 
                                exponential (2, 13, 0, 2)}; 
    vector <cubic> cubic_list =
                               {cubic (1, 3, 3, 1, -2, 2),
                                cubic (1, 2, 4, -1, 0, 2), 
                                cubic (1, 8, -6, -5, -3, 2),  
                                cubic (1, -3, 3, -1, 0, 2), };         

    cout<< "Have no root on this segment:" << endl;
    int tmp = 1;
    for (auto a: lin_list)
    {
        a.solve();
        if (a.get_not_work())
        {
            //a.show();
        }
        else
        {
            sum+=a.get_root();
            if (tmp)
            {
                tmp = 0;
                biggest = a.get_root();
                abs_end = a.get_end();
                abs_start = a.get_start();
            }
            else
            {
                if (biggest < a.get_root())
                {
                    biggest = a.get_root();
                }
                if (abs_end > a.get_end())
                {
                    abs_end = a.get_end();
                }
                if (abs_start > a.get_start())
                {
                    abs_start = a.get_start();
                }
                
            }
        }
    }



    for (auto a: sin_list)
    {
        a.solve();
        if (a.get_not_work())
        {
            //a.show();
        }
        else
        {
            sum+=a.get_root();
            if (tmp)
            {
                tmp = 0;
                biggest = a.get_root();
                abs_end = a.get_end();
                abs_start = a.get_start();
            }
            else
            {
                if (biggest < a.get_root())
                {
                    biggest = a.get_root();
                }
                if (abs_end > a.get_end())
                {
                    abs_end = a.get_end();
                }
                if (abs_start > a.get_start())
                {
                    abs_start = a.get_start();
                }
                
            }
        }
    }


    for (auto a: exp_list)
    {
        a.solve();
        if (a.get_not_work())
        {
            //a.show();
        }
        else
        {
            sum+=a.get_root();
            if (tmp)
            {
                tmp = 0;
                biggest = a.get_root();
                abs_end = a.get_end();
                abs_start = a.get_start();
            }
            else
            {
                if (biggest < a.get_root())
                {
                    biggest = a.get_root();
                }
                if (abs_end > a.get_end())
                {
                    abs_end = a.get_end();
                }
                if (abs_start > a.get_start())
                {
                    abs_start = a.get_start();
                }
                
            }
        }
    }

    for (auto a: cubic_list)
    {
        a.solve();
        if (a.get_not_work())
        {
            //a.show();
        }
        else
        {
            sum+=a.get_root();
            if (tmp)
            {
                tmp = 0;
                biggest = a.get_root();
                abs_end = a.get_end();
                abs_start = a.get_start();
            }
            else
            {
                if (biggest < a.get_root())
                {
                    biggest = a.get_root();
                }
                if (abs_end > a.get_end())
                {
                    abs_end = a.get_end();
                }
                if (abs_start > a.get_start())
                {
                    abs_start = a.get_start();
                }
                
            }
        }
    }


    cout<< "Sum:" << sum<<endl;
    cout<<"biggest:" << biggest<<endl;
    if (abs_end<abs_start)
    {
        cout<< "No segment"<< endl;
    }
    else
    {
        cout << "[" << abs_start << ", " << abs_end << "]" << endl;
    }
}