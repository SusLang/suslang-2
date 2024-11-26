//
// Created by migouche on 16-Nov-24.
//

#ifndef SUSLANG2_TOKEN_H
#define SUSLANG2_TOKEN_H

#include <string>
#include <utility>

enum TokenKind{
    // UTF-8 CHARS
    END, TAB, MAIN, ARROW, COMMENT,

    // TOKENS WITH VALUE
    IDENTIFIER, LITERAL, OPERATOR, COLON,

    // UTILITIES
    OPEN_PAREN, CLOSE_PAREN, COMMA, DOUBLE_QUOTE,

    // KEYWORDS
    TASK, CREWMATE, SUS, CLEAN, IF_SUS, ELSE_CLEAN, EJECT, MAKE, COMPLETE, REPORT, WITH
};

class Token {
private:
    TokenKind kind;
    std::string value;
    int line, column;

public:
    Token(TokenKind kind, std::string value, int line = 0, int column = 0) : kind(kind), value(std::move(value)), line(line), column(column) {}

    [[nodiscard]] TokenKind get_kind() const {
        return kind;
    }

    [[nodiscard]] const std::string &get_value() const {
        return value;
    }

    [[nodiscard]] int get_line() const {
        return line;
    }

    [[nodiscard]] int get_column() const {
        return column;
    }

    [[nodiscard]] std::string to_string() const;
};

#endif //SUSLANG2_TOKEN_H
