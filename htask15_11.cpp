#include <iostream>
#include <fstream>
#include <vector>


//15_11
using namespace std;

class book
{
private:
    string name;
    string Author;
    unsigned int pages;
    unsigned int year;
public:
    book(){}
   ~book(){}

    void setname(string nm)
    {
        name = nm;
    }
    string getname()
    {
        return name;
    }
    void setauthor(string nstthr)
    {
        Author = nstthr;
    }
    string getauthor()
    {
        return Author;
    }   
    void setpages(unsigned int a)
    {
        pages = a;
    }
    unsigned int getpages()
    {
        return pages;
    }   
    void setyear(unsigned int a)
    {
        year = a;
    }
    unsigned int getyear()
    {
        return year;
    }   
    
    void set_book_console()
    {
        cout << "Print name: ";
        string tmp_name;
        cin >> tmp_name;
        setname(tmp_name);

        cout << "Print author: ";
        string tmp_author;
        cin >> tmp_author;
        setauthor(tmp_author);

        cout << "Print pages: ";
        unsigned int tmp_pages;
        cin >> tmp_pages;
        setpages(tmp_pages);

        cout << "Print year: ";
        unsigned int tmp_year;
        cin >> tmp_year;
        setyear(tmp_year);
    }

    void set_book(string nm, string thr, unsigned int pgs, unsigned int r)
    {
        setname(nm);
        setauthor(thr);
        setpages(pgs);
        setyear(r);
    }

    void show_book()
    {
        cout << "Name: " << getname() << endl;
        cout << "Author: " << getauthor() << endl;
        cout << "Pages: " << getpages() << endl;
        cout << "Year: " << getyear() << endl;
    }
};



int main()
{
    fstream f;
    f.open("test15_11.txt", ios::in);
    vector <book> lst;

    while(!f.eof())
    {
        book temp;

        string nm;
        string thr;

        string tmp;
        unsigned int pgs;
        unsigned int r;

        getline(f, nm);
        getline(f, thr);
        getline(f, tmp);
        pgs = stoi(tmp);
        getline(f, tmp);
        r = stoi(tmp);
        temp.set_book(nm, thr, pgs, r);
        //temp.show_book();
        
        lst.push_back(temp);
        getline(f, tmp);
    }

    cout << "Find by author or name 0/1: ";
    int a = 2;
    cin >> a;
    string tmp = "";
    int y = 1;
    if (a==1)
    {
        cout << "Name of book: ";
        cin >> tmp; 
        for (book j: lst)
        {
            if (j.getname() == tmp)
            {
                j.show_book();
                y = 0;
                break;
            }
        }
    }
    if (a==0)
    {
        cout << "Author of book: ";
        cin >> tmp; 
        for (book j: lst)
        {
            if (j.getauthor() == tmp)
            {
                j.show_book();
                y = 0;
                break;
            }
        }
    }
    if (y)
    {
        cout << "Book was not found" << endl;
    }
    if ((a!=0)&&(a!=1))
    {
        cout<< "Something went wrong"<<endl;
    }
    




    f.close();
}
