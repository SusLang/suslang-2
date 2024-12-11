//
// Created by migouche on 16-Nov-24.
//

#include "analyzer/ast.h"


#include "analyzer/token.h"
#include "utils/assert.h"

using namespace Analyzer;

AST::AST(const std::vector<Token>& tokens) {
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        ASSERT(it->get_kind() == TokenKind::TASK, "Expected a task declaration (other declarations not supported yet)");
        declarations.emplace_back(it);
    }
}