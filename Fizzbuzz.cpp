#include <iostream>

using namespace std;

string fizzbuzz(int number)
{
    if(((number % 3)!= 0) && ((number % 5)!= 0)) //nummer nicht teilbar durch 3 und 5
    {
        return to_string(number);
    }
    else if(((number % 3) == 0) && ((number % 5)== 0)) //nummer teilbar durch 3 und 5
    {
        return "fizzbuzz";
    }
    else if((number % 3) == 0 ) //teilbar durch 3
    {
        return "fizz";
    }
    else if((number % 5) == 0) //teilbar durch 5
    {
        return "buzz";
    } 
}




int main()
{

    cout<<fizzbuzz(15)<<endl;

    return 0;
}
