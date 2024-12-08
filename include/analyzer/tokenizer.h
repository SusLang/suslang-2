//
// Created by migouche on 16-Nov-24.
//

#ifndef SUSLANG2_TOKENIZER_H
#define SUSLANG2_TOKENIZER_H

#include <string>
#include <vector>
#include "analyzer/token.h"

namespace Analyzer {
    class Tokenizer {
    public:
        explicit Tokenizer(const std::string &source);
        const std::vector<Token>& get_tokens() const;
    private:
        std::vector<Token> tokens;
        std::string buff;
        void emplace_back(const std::string& utf8);
    };
}
#endif //LILAC_TOKENIZER_H
