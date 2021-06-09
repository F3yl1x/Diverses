#include<iostream>
#include<vector>

void func(std::string s){
    int size = s.size();
    for(int i = 0;i<size;i+=2){
        std::cout<<s[i];
    }
    return;
}

int produkt(std::vector<int> eingabe)
{
    int size = eingabe.size();
    int merker= 1;
    for(int i=0; i < size;i++)
    {
        merker = eingabe[i] * merker;
    }

    return merker;
}

std::string verdoppeln(std::string s)
{
    std::string merker = s;
    int size = s.size();
    for(int i=0;i<size;i++)
    {
        merker.push_back(s[i]);
    }
    return s+s;
}

std::vector<int> operator+(const std::vector<int> &eingabe1, const std::vector<int> &eingabe2)
{   
    std::vector<int> dieser = eingabe1;
    for(int i = 0; i<eingabe2.size(); i++)
    {
        dieser.push_back(eingabe2[i]);
    }
    return dieser;
}

int foo(int x, int y)
{
    std::cout << x;
    return x + y;
}

void bar(int &k)
{
    int y = k;
    for(char b = 3; b >= -1; b--)
    {
        k = foo(y,b);
    }
}

class name {
protected :
std::string vorname = "Max";
std::string nachname = "Mustermann";
public :
void print() { std::cout << vorname << " " << nachname << "\n"; }
virtual int length() { return vorname.size() + nachname.size() + 1; }
};


class firmenname : public name {
public :
firmenname() { nachname = "AG"; }
void print() { std::cout << nachname << "\n"; }
virtual int length() { return nachname.size(); }
};

template <typename T>

std::vector<T> replace(std::vector<T> v,T x,T y)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i]== x) 
        {
            v[i] = y;
        }
    }
    return v;
}

int &zurueck(int &test)
{
    return test;
}





int main(){
    // func("Testen");
    // std::cout << std::endl;

    // std::vector<int> test;
    // test.push_back(4);
    // test.push_back(2);
    // test.push_back(6);
    // std::cout << produkt(test) << std::endl;
    // std::cout << verdoppeln("Hallo") << std::endl;´


    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);

    std::vector<int> vec2;
    vec2.push_back(3);
    vec2.push_back(4);

    std::vector<int> vec3;

    vec3 = vec1 + vec2;

    for (int i = 0; i < vec3.size(); i++)
    {
        std::cout << vec3[i] << std::endl;
    }

    int hallo = 1;
    int teest = zurueck(hallo);
    std::cout << "Test: " << teest << std::endl;

    // int x = 1;
    // while (x != 0) bar(x);

    // name n;
    // firmenname f;
    // name &rn = n;
    // name * pf = &f;

    // n.print();
    // std::cout << n.length() << "\n";
    // f.print();
    // std::cout << f.length() << "\n";

    // rn.print();
    // std::cout << rn.length() << "\n";
    // pf->print ();
    // std::cout << pf ->length () << "\n";

    // std::vector<int> vec1 = {1,2,2,4,2,6};
    // std::vector<int> vec2 = replace(vec1,2,10);
    // for (int i = 0; i < vec2.size(); i++)
    // {
    //     std::cout<< vec2[i]<< std::endl;
    // }

    return 0;
}