//
// Created by migouche on 10/12/24.
//

#ifndef ASSERT_H
#define ASSERT_H

#include <iostream>
#include <cassert>

#define ASSERT(cond, msg) \
    do { \
        if (!(cond)) { \
        std::cerr << "Assertion failed: (" #cond ") in " << __FILE__ << " line " << __LINE__ << ": " << msg << std::endl; \
        assert(cond); \
        } \
    } while (false)

#endif //ASSERT_H
