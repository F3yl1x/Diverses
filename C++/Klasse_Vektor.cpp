#include <iostream>

using namespace std;


class vek
{
    private:
        int _x;
        int _y;
        int _z;
    
    public:
    vek(int x, int y, int z) {_x=x; _y=y; _z=z;}
    vek() {_x=0; _y=0; _z=0;}
    friend ostream& operator <<(ostream& os, vek b);
    vek operator+ (const vek &eingabe);
    friend int skalarprodukt(const vek&eingabe1, const vek&eingabe2);
    int x(){return this ->_x;};
    int y(){return this ->_y;};
    int z(){return this ->_z;};

    };


ostream& operator << (ostream& os, vek b)
{
    cout<< "(" << b.x() << ")" << endl << "(" << b.y() << ")" << endl << "(" << b.z() << ")" << endl;
}

vek vek::operator+(const vek &eingabe)
{
    vek ausgabe((this ->_x + eingabe._x), (this ->_y + eingabe._y), (this ->_z + eingabe._z));
    return ausgabe;
}

int skalarprodukt(const vek&eingabe1, const vek&eingabe2)
{
    int merker = (eingabe1._x * eingabe2._x) + (eingabe1._y * eingabe2._y) + (eingabe1._z * eingabe2._z);
    return merker;
}

int main()
{

    vek test1(2,-6,4);
    vek test2(-1,2,3);
    vek test3 = test1+test2;
    
    cout<< test1<<  endl << test2 << endl << test3 << endl << "Skalarprodukt: " << skalarprodukt(test1,test2) << endl;

    return 0;

}