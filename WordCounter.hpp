#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>

class WordCounter{
    public:
        string read_file(const string& filepath);
        map<string, int> count_words();
        string format_output();
        
        string getDocument(){
            return this->document;
        }
        map<string, int> getWordsCounted(){
            return this->words_counted;
        }

    private:
        string document;
        map<string, int> words_counted;
};

#endif