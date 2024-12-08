//
// Created by migouche on 16-Nov-24.
//

#include <iostream>

#include "compiler/compiler.h"

int main() {
    //Tokenizer t("data/helloworld.sus");
    Compiler::Compiler c({"data/helloworld.sus"});

    return 0;
}
