cmake_minimum_required(VERSION 3.11.0)

project(Lilac)

if(UNIX AND NOT APPLE)
    include_directories(~/local/include)
endif ()

#find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

message(STATUS "Found Clang ${Clang_PACKAGE_VERSION}")
message(STATUS "Using ClangConfig.cmake in: ${Clang_DIR}")

set(LLVM_TARGETS_TO_BUILD "X86;x64" CACHE STRING "" FORCE)
set(DLLVM_USE_LINDER lld)
set(BUILD_SHARED_LIBS  ON)
add_definitions(-DLLVM_DISABLE_EXP_DEBUGINFO_ITERATORS)
set(LLVM_BUILD_SHARED_LIBS ON)


message("llvm include: ${LLVM_INCLUDE_DIRS}")
message("clang include: ${CLANG_INCLUDE_DIRS}")

include_directories(include)
include_directories(${LLVM_INCLUDE_DIRS})

add_definitions(${CLANG_DEFINITIONS})

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp include/*.h)

set(CMAKE_CXX_STANDARD 23)

add_link_options(-fsanitize=address,undefined,leak,signed-integer-overflow,bounds)

add_executable(suslang2 src/main.cpp ${SOURCE_FILES})

llvm_map_components_to_libnames(LLVM_LIBS
        core
        support
        irreader
        target
        mc
        X86
        # Add other required components here
)

# Map Clang components to library names
set(CLANG_LIBS
        clangDriver
        clangCodeGen
        clangFrontend
        clangLex
        clangParse
        # Add other required components here
)

message(STATUS "LLVM_LIBS: ${LLVM_LIBS}")
message(STATUS "CLANG_LIBS: ${CLANG_LIBS}")

# Ensure no duplicate libraries are linked
list(REMOVE_DUPLICATES LLVM_LIBS)
list(REMOVE_DUPLICATES CLANG_LIBS)

target_link_libraries(suslang2 ${LLVM_LIBS})