//
// Created by migouche on 9/12/24.
//

#ifndef ASTDECLARATION_H
#define ASTDECLARATION_H

#include <vector>

#include "astnode.h"

namespace Analyzer {
    class Token;
}

namespace Analyzer::Nodes {
    class ASTDeclaration: public ASTNode {
    public:
        explicit ASTDeclaration(std::vector<Token>::const_iterator& it);
        ~ASTDeclaration() override = default;
    };
}

#endif //ASTDECLARATION_H
