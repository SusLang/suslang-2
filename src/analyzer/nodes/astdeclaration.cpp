//
// Created by migouche on 9/12/24.
//

#include "analyzer/nodes/astdeclaration.h"

#include "analyzer/token.h"
#include "utils/assert.h"

using namespace Analyzer::Nodes;

ASTDeclaration::ASTDeclaration(std::vector<Token>::const_iterator& it) {
    ASSERT(it->get_kind() == TASK, "Expected a task declaration");
    ++it;
    ASSERT(it->get_kind() == IDENTIFIER, "Expected a task name");
    
}

