#include <iostream>

using namespace std;

class bruch
{
private:
    int z;
    int n;

public:
    bruch();
    bruch(int pz, int pn): z(pz), n(pn) {};
    void ausgeben();
    void kgt(bruch v);
    void ggt(bruch v);
    bruch operator+(const bruch& obj);
    bruch operator*(const bruch& obj);
    bruch operator/(const bruch& obj);
    bruch operator-(const bruch& obj);
    void setzen(int pz, int pn);

};

void bruch::ausgeben()
{
    cout << z <<"/" << n<<endl;
}

void bruch::kgt(bruch v)
{
  for(int i=1; i<1000; i++)
  {
      if(((n*i%v.n) == 0) and ((v.n*i%n) == 0))
      {
          cout << "Der kGT ist: " << i << endl;
          break;
      }
  }
}
void bruch::ggt(bruch v)
{
    int i = n * v.n;
    cout << "Der gGT ist: " << i << endl;
  
}

bruch bruch::operator+(const bruch& obj)
{
    bruch h(0,0);
    h.z = z * obj.n + obj.z * n;
    h.n = n * obj.n;
    int i;
    for(i=1000; i>0; i--)
    {
        if(((h.z%i) == 0) and ((h.n%i) == 0))
        {
            break;
        }
    }
    h.z = h.z / i;
    h.n = h.n / i;
    return h;
}

bruch bruch::operator*(const bruch& obj) {
    bruch h(0,0);
    h.z = z * obj.z;
    h.n = n * obj.n;
    int i;
    for(i=1000; i>0; i--)
    {
        if(((h.z%i) == 0) and ((h.n%i) == 0))
        {
            break;
        }
    }
    h.z = h.z / i;
    h.n = h.n / i;
    return h;
}

bruch bruch::operator/(const bruch& obj) {
    bruch h(0,0);
    h.z = z * obj.n;
    h.n = n * obj.z;
    int i;
    for(i=1000; i>0; i--)
    {
        if(((h.z%i) == 0) and ((h.n%i) == 0))
        {
            break;
        }
    }
    h.z = h.z / i;
    h.n = h.n / i;
    return h;
}

bruch bruch::operator-(const bruch& obj) {
    bruch h(0,0);
    h.z = z * obj.n - obj.z * n;
    h.n = n * obj.n;
    int i;
    for(i=1000; i>0; i--)
    {
        if(((h.z%i) == 0) and ((h.n%i) == 0))
        {
            break;
        }
    }
    h.z = h.z / i;
    h.n = h.n / i;
    return h;
}

void bruch::setzen(int pz, int pn)
{
    z = pz;
    n = pn;
}


int main()
{
    bruch a(7,8), b(15,20),x(0,0);
    
    cout<< "a: ";
    a.ausgeben();
    cout<< "b: ";
    b.ausgeben();
    
    cout<<"a+b: ";
    x= a+b;
    x.ausgeben();
    
    cout<<"a-b: ";
    x= a-b;
    x.ausgeben();
    
    cout<<"a*b: ";
    x= a*b;
    x.ausgeben();
    
    cout<<"a/b: ";
    x= a/b;
    x.ausgeben();
    
    bruch c(0,0);
    
    x.setzen(1,6);
    
    x.ausgeben();
    
    a.kgt(b);
    
    a.ggt(b);

    return 0;
}
