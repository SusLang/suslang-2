//
// Created by migouche on 16-Nov-24.
//

#ifndef LILAC_AST_H
#define LILAC_AST_H
#include <vector>

#include "token.h"
#include "nodes/astdeclaration.h"
namespace Analyzer {
    // Define AST nodes
    class AST {
    private:
        std::vector<Nodes::ASTDeclaration> declarations;
        // all code is a list of function / global variable / include declarations
    public:
        explicit AST(const std::vector<Token>&);

    };

}
#endif //LILAC_AST_H
