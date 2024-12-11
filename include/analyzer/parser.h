//
// Created by migouche on 10-Dec-24.
//

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "analyzer/token.h"

namespace Analyzer {
    class Token;

    class Parser {
    public:
        explicit Parser(const std::vector<Token> &tokens);

        void parse();
    };
}

#endif //PARSER_H
