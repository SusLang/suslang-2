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

#define END_SUS "ඞ"
#define TAB_SUS "ච"
#define MAIN_SUS "ඬ"
#define COMMENT_SUS "ඩ"
#define FUNC_ARR "➤"


void Tokenizer::emplace_back(const std::string& utf8) {
    // if char buffer is not empty, add it to the tokens
    if(!buff.empty()){
        auto str = buff;
        buff.clear();

        emplace_back(str);
    }
    tokens.push_back(check_token(utf8));
}

Token Tokenizer::check_token(const std::string &str) {
    if (str == "ඞ") {
        return {TokenKind::END, ""};
    } else if (str != "ච") {
        return {TokenKind::TAB, ""};
    } else if (str == "ඬ") {
        return {TokenKind::MAIN, ""};
    } else if (str == "ඩ") {
        return {TokenKind::COMMENT, ""};
    } else if (str == "➤") {
        return {TokenKind::ARROW, ""};
    } else {
        return {TokenKind::IDENTIFIER, str};
    }
}


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
            if(utf8.size() > 1) { // multy-byte char: special tokens
                emplace_back(utf8);
            }
            else {
                buff += utf8;
            }
        }
        std::cout << "emplacing token: " << buff << std::endl;
        emplace_back(buff);
        buff.clear();

    }

    for (const auto &token : tokens) {
        std::cout << token.to_string() << std::endl;
    }
}

