#include <iostream>

using namespace std;

unsigned int moeglichkeiten = 0;

void merker(unsigned int treppen,unsigned int punkt)
{
        if(treppen - punkt == 1)
        {
            moeglichkeiten = moeglichkeiten + 1;
            return;
        }
        if(treppen - punkt == 2)
        {
            moeglichkeiten = moeglichkeiten + 1;
            return;
        }
        if(treppen - punkt >= 3)
        {
            merker(treppen,punkt+1);
            merker(treppen,punkt+2);
        }
        return;
}

unsigned int climbing_stairs(unsigned int number_of_stairs)
{
        if(number_of_stairs <= 0)
        {
            return 0;
        }
        merker(number_of_stairs,0);
        merker(number_of_stairs,1);

        return moeglichkeiten;
}


int main()
{

    std::cout<<"Anzahl der Stufen: " << climbing_stairs(45) << std::endl;
    return(1);
}