//
// Created by migouche on 16-Nov-24.
//

#include <fstream>
#include <iostream>
#include <locale>
#include "analizer/tokenizer.h"
#include "str/str.h"

#define END_SUS "ඞ"
#define TAB_SUS "ච"
#define MAIN_SUS "ඬ"
#define COMMENT_SUS "ඩ"
#define FUNC_ARR "➤"

inline bool is_special_char(char a) {
    return a == '"' || a == '(' || a == ')' || a == ',' || a == ':' || a == 'ඞ' || a == 'ච' || a == 'ඬ' || a == '➤';
}


Token check_keyword(const std::string& str){
    if (str == "task")
        return {TASK, ""};
    if (str == "crewmate")
        return {CREWMATE, ""};
    if (str == "sus")
        return {SUS, ""};
    if (str == "clean")
        return {CLEAN, ""};
    if (str == "sus?")
        return {IF_SUS, ""};
    if (str == "clean?")
        return {ELSE_CLEAN, ""};
    if (str == "eject")
        return {EJECT, ""};
    if (str == "make")
        return {MAKE, ""};
    if (str == "complete")
        return {COMPLETE, ""};
    if (str == "report")
        return {REPORT, ""};
    if (str == "with")
        return {WITH, ""};
    return {IDENTIFIER, str};
}

Token check_token(const std::string &str) {
    if (str == "ඞ")
        return {END, ""};
    if (str == "ච")
        return {TAB, ""};
    if (str == "ඬ")
        return {MAIN, ""};
    if (str == "ඩ")
        return {COMMENT, ""};
    if (str == "➤")
        return {ARROW, ""};
    if (str == "(")
        return {OPEN_PAREN, ""};
    if (str == ")")
        return {CLOSE_PAREN, ""};
    if (str == ",")
        return {COMMA, ""};
    if (str == ":")
        return {COLON, ""};
    if (str == "\"")
        return {DOUBLE_QUOTE, ""};
    return check_keyword(str);

}

void Tokenizer::emplace_back(const std::string& utf8) {
    // if char buffer is not empty, add it to the tokens
    if(!buff.empty()){
        const auto str = buff;
        buff.clear();

        emplace_back(str);
    }
    if (utf8.empty()) {
        return;
    }
    tokens.push_back(check_token(utf8));
}


Tokenizer::Tokenizer(const std::string &source) {
    std::ifstream file(source);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + source);
    }


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
        emplace_back(buff);
        buff.clear();

    }

    for (const auto &token : tokens) {
        std::cout << token.to_string() << std::endl;
    }
}

