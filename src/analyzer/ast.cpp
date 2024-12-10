//
// Created by migouche on 16-Nov-24.
//

#include "analyzer/ast.h"


#include "analyzer/token.h"
#include "utils/assert.h"

using namespace Analyzer;

AST::AST(const std::vector<Token>& tokens) {
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        ASSERT(it->get_kind() == TokenKind::TASK, "Expected a task declaration");
        ++it;
        std::string name;
        if (it->get_kind() == MAIN) {
            name = "main";
        } else {
            ASSERT(it->get_kind() == TokenKind::IDENTIFIER, "Expected a task name");
            name = it->get_value();
        }
        ++it;
        ASSERT(it->get_kind() == WITH, "Expected a with keyword");
    }
}