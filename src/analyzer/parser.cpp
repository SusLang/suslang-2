//
// Created by migouche on 10-Dec-24.
//

#include "analyzer/parser.h"

#include <vector>

#include "analyzer/token.h"
#include "analyzer/nodes/functiondeclaration.h"
#include "utils/assert.h"


namespace Analyzer {
    class Token;
}

using namespace Analyzer;

Parser::Parser(const std::vector<Analyzer::Token>& tokens) {
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        ASSERT(it->get_kind() == TokenKind::TASK, "Expected a task declaration (other declarations not supported yet)");

    }
}

Nodes::FunctionDeclaration parse_function_declaration(std::vector<Token>::const_iterator& it) {
    ASSERT(it->get_kind() == TokenKind::TASK, "Expected a task declaration (other global declarations not supported yet)");
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

    // arguments are of type name1: type1 and name2: type2

    std::vector<std::pair<std::string, std::string>> arguments; // name, type

    while (true) {
        std::string arg_name = it->get_value();
        ++it;
        ASSERT(it->get_kind() == TokenKind::COLON, "Expected a colon");
        ++it;
        ASSERT(it->get_kind() == TokenKind::IDENTIFIER, "Expected a type");
        std::string arg_type = it->get_value();
        arguments.emplace_back(arg_name, arg_type);
        ++it;
        if (it->get_kind() == ARROW)
            break;
        ASSERT(it->get_kind(), "Expected 'and' or an arrow");
    }
    ++it;

}