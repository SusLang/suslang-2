//
// Created by migouche on 16-Nov-24.
//

#ifndef LILAC_TOKENIZER_H
#define LILAC_TOKENIZER_H

#include <string>
#include <vector>
#include "analizer/token.h"



class Tokenizer {
public:
    explicit Tokenizer(const std::string &source);
private:
    std::vector<Token> tokens;
    std::string buff;
    void emplace_back(const std::string& utf8);
};

#endif //LILAC_TOKENIZER_H
