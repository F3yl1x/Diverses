#include <iostream>
#include <vector>

using namespace std;

void pruefung(vector<int> num, int pos,bool &work)
{   
    if (work==true) return;
    if(num[pos] + pos >= num.size()-1)
    {
        work = true;
        return;
    }
    for(int i = 1; i <= num[pos] ;i++)
    {
        pruefung(num,pos+i,work);
    }
}

bool isCompleteable(vector<int> numbers)
{
    bool working = 0;
    pruefung(numbers,0,working);
    return working;

}

void pruefung2(vector<int> num, int pos,int sprung, int &main_jump)
{   
    if(sprung >= main_jump && main_jump != 0) return;
    else
    {
        sprung++;
        cout<<"Spruenge: " << sprung << endl;
        if(num[pos] + pos >= num.size()-1)
        {
            if(sprung < main_jump || main_jump == 0)
            {
                main_jump = sprung;
                return;
            }
        }
        for(int i = 1; i <= num[pos] ;i++)
        {
            pruefung2(num,pos+i,sprung,main_jump);
        }
        return;
    }
}

int getMinimalNumberOfJumps(std::vector<int> numbers){
    int jumps = 0;
    pruefung2(numbers,0,0,jumps);
    return jumps;
}

int main()
{
    vector<int> test1 = {1,3,0,0,1,5,1,1,1,1,1,1,5};
    vector<int> test3 = {1,4,3,4,5};
    vector<int> test2 = {2,0,3};
    vector<int> test4 = {3,2,0,1,2};
    cout << isCompleteable(test2) << endl;
    cout << getMinimalNumberOfJumps(test4);
}