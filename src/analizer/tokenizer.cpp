//
// Created by migouche on 16-Nov-24.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <codecvt>
#include <locale>
#include "analizer/tokenizer.h"
#include "str/str.h"

#define END_SUS u8'ඞ'
#define TAB_SUS u8'ච'
#define MAIN_SUS u8'ඬ'
#define COMMENT_SUS u8'ඩ'
#define FUNC_ARR u8'➤'


Tokenizer::Tokenizer(const std::string &source) {
    std::ifstream file(source);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + source);
    }

    /*std::string line;
    while(file >> line) {
        std::cout << line << ", size: " << line.size() << std::endl;
    }*/
    std::string word;
    while(file >> word) {
        while(!word.empty()) {
            std::string utf8 = str::substr(word, 0, 1);
            word.erase(0, utf8.size());
            std::cout << utf8;
        }
        std::cout << std::endl;
    }
}