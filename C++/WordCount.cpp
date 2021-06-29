#include "WordCounter.hpp"

string WordCounter::read_file(const string &filepath)
{
    ifstream datei(filepath);
    string zeile;
    vector<string> vec_d;
    document.clear();

    if(datei.is_open())
    {
        while(getline(datei,zeile))
        {   
            vec_d.push_back(zeile);
        }
    }
    else
    {
        std::cout << "Datei konnte nicht geöffnet werden"<<std::endl;
        return "NO FILE";
    }

    for(int i = 0; i < (vec_d.size()-1);i++)
    {
        document.insert(document.size(),vec_d[i]);
        document.insert(document.size(),"\n");
    }
    document.insert(document.size(),vec_d[vec_d.size()-1]);

    return document;
}

map<string, int> WordCounter::count_words()
{
    string wort;
    vector<string> vec_w;
    char merker;
    map<string,int>::iterator it;
    words_counted.clear();

    for(int i = 0; i < document.size();i++)
    {   
        merker = document[i];
        if(merker == ' ' || merker== '\n' || merker== ',' || merker== '\r' || merker== '.')
        {
            if(wort.size()!=0)
            {
                vec_w.push_back(wort);
                wort.clear();
            }
        }
        else
        {
            wort.push_back(merker);
        }
    }
    if(wort.size()!=0)
            {
                vec_w.push_back(wort);
                wort.clear();
            }
    for(int i = 0; i < vec_w.size();i++)
    {   
        it = words_counted.find(vec_w[i]);
        if (it != words_counted.end())
        {
            words_counted.at(vec_w[i]) ++;
        }
        else
        {
            words_counted.insert(make_pair(vec_w[i],1));
        }
    }
    return words_counted;
}

string WordCounter::format_output()
{   
    string ausgabe;
    int wortanzahl = 0;
    for (auto iter = words_counted.begin(); iter != words_counted.end(); ++iter)
    {
        ausgabe.insert(ausgabe.size(),iter->first);
        ausgabe.insert(ausgabe.size()," : ");
        ausgabe.insert(ausgabe.size(),to_string(iter->second));
        ausgabe.insert(ausgabe.size(),",\n");
        wortanzahl += iter->second;
    }
    ausgabe.insert(ausgabe.size(),"--------------------------\nTotal Words: ");
    ausgabe.insert(ausgabe.size(),to_string(wortanzahl));

    return ausgabe;
}

int main()
{   
    //Erste Funktion
    string hi;
    WordCounter Test;

    hi = Test.read_file("text0.txt");
    cout<< hi << endl;


    //Zweite Funktion
    map<string, int> hii;

    hii = Test.count_words();

    cout << endl <<"{"<< endl;
    for (auto iter = hii.begin(); iter != hii.end(); ++iter)
    {
        cout << "\t" << iter->first << " => " << iter->second << ",\n";
    }
    cout << "}"<< endl;


    //Dritte Funktion
    string tester = Test.format_output();
    cout << tester << endl;

    return EXIT_SUCCESS;
}