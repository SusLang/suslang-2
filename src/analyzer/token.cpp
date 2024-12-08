//
// Created by migouche on 24-Nov-24.
//

#include "analyzer/token.h"

using namespace Analyzer;

inline std::string tokenkind_str(const TokenKind& t) {
    switch (t) {
        case TokenKind::END: return "END";
        case TokenKind::TAB: return "TAB";
        case TokenKind::MAIN: return "MAIN";
        case TokenKind::ARROW: return "ARROW";
        case TokenKind::COMMENT: return "COMMENT";
        case TokenKind::IDENTIFIER: return "IDENTIFIER";
        case TokenKind::LITERAL: return "LITERAL";
        case TokenKind::OPERATOR: return "OPERATOR";
        case TokenKind::OPEN_PAREN: return "OPEN_PAREN";
        case TokenKind::CLOSE_PAREN: return "CLOSE_PAREN";
        case TokenKind::TASK: return "TASK";
        case TokenKind::CREWMATE: return "CREWMATE";
        case TokenKind::SUS: return "SUS";
        case TokenKind::CLEAN: return "CLEAN";
        case TokenKind::IF_SUS: return "SUS?";
        case TokenKind::ELSE_CLEAN: return "CLEAN?";
        case TokenKind::EJECT: return "EJECT";
        case TokenKind::MAKE: return "MAKE";
        case TokenKind::COMMA: return "COMMA";
        case TokenKind::COLON: return "COLON";
        case TokenKind::COMPLETE: return "COMPLETE";
        case TokenKind::REPORT: return "REPORT";
        case TokenKind::WITH: return "WITH";
        case TokenKind::DOUBLE_QUOTE: return "DOUBLE_QUOTE";
    }
}

std::string Token::to_string() const {
    return "Token(" + tokenkind_str(kind) + ", " + value + ")";
}