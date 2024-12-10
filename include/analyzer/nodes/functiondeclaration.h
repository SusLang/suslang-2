//
// Created by migouche on 9/12/24.
//

#ifndef FUNCTIONDECLARATION_H
#define FUNCTIONDECLARATION_H

#include <vector>

#include "astdeclaration.h"
#include "analyzer/token.h"

namespace Analyzer::Nodes {
    class FunctionDeclaration final : public ASTDeclaration {
    public:
        explicit FunctionDeclaration(std::vector<Token>::const_iterator& it);

        ~FunctionDeclaration() override = default;
    };
}

#endif //FUNCTIONDECLARATION_H
