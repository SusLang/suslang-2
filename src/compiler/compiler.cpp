//
// Created by migouche on 08-Dec-24.
//

#include "compiler/compiler.h"

using namespace Analyzer;

::Compiler::Compiler::Compiler(const std::vector<std::string> &sources): tokenizer(sources.at(0)) {
}
