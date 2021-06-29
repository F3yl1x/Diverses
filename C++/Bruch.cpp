#include <iostream>

class bruch{
private:
    int _z;
    int _n;
public:
bruch(int z, int n):_z(z), _n(n){};
bruch(int z): _z(z), _n(1){};
bruch();
int zaehler() { return _z;};
int nenner() {return _n;};
void kuerzen();
bruch inverse();
bruch operator+(const bruch b);
friend std::ostream& operator <<(std::ostream& os, bruch b);

//bruch operator<<();
};

bruch bruch::inverse()
{
int merker = _z;
_z = _n;
_n = merker;
}
void bruch::kuerzen()
{
for(int i = 100; i >1; i--)
{
if((_z%i) == 0 && (_n%i) == 0)
{
_z = _z/i;
_n = _n/i;
return;
} 
}
}

bruch bruch::operator+(bruch b)
{
    bruch c((_z*b.nenner()) + (b.zaehler()*_n),_n * b.nenner());
    return c;

}

std::ostream& operator <<(std::ostream& os, bruch b)
{
    os << b.zaehler() << "/" << b.nenner();
    return os;
}


int  main()
{
    bruch a(3, 4);
    bruch b(2, 4);
    b.kuerzen ();
    bruch c = a + b;
    c.kuerzen();
    std:: cout  << "b = " << c<< std::endl << a << std::endl << b <<  std::endl;
    return  EXIT_SUCCESS;}