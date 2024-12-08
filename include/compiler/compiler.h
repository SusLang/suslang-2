//
// Created by migouche on 08-Dec-24.
//

#ifndef SUSLANG2_COMPILER_H
#define SUSLANG2_COMPILER_H

#include "analyzer/ast.h"
#include "analyzer/tokenizer.h"

namespace Compiler {
    class Compiler {
    private:
        Analyzer::Tokenizer tokenizer;
    public:
        explicit Compiler(const std::vector<std::string> &sources);
        const std::vector<Analyzer::Token> get_tokens() const;
    };
}

#endif //COMPILER_H
