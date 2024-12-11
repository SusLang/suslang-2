//
// Created by migouche on 9/12/24.
//

#include "analyzer/nodes/astdeclaration.h"

#include "analyzer/token.h"
#include "utils/assert.h"

using namespace Analyzer::Nodes;

ASTDeclaration::ASTDeclaration(std::vector<Token>::const_iterator& it) {
    ASSERT(it->get_kind() == TASK, "Expected a task declaration (other global declarations not supported yet)");
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
    ++it;

}

