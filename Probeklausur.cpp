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

int main(){
    func("Testen");
    std::cout << std::endl;

    std::vector<int> test;
    test.push_back(4);
    test.push_back(2);
    test.push_back(6);
    std::cout<< produkt(test) << std::endl;
    std::cout<<verdoppeln("Hallo")<<std::endl;
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);

    std::vector<int> vec2;
    vec2.push_back(3);
    vec2.push_back(4);

    std::vector<int> vec3;

    vec3= vec1 + vec2;

    for(int i = 0; i<vec3.size(); i++)
    {
        std::cout<< vec3[i]<<std::endl;
    }


    return 0;
}