cmake_minimum_required(VERSION 3.11)
project(Jaguar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# =========================
# BISON
# =========================
set(BISON_EXECUTABLE "C:/Program Files/msys2/usr/bin/bison.exe")
find_package(BISON REQUIRED)
BISON_TARGET(
  JaguarParser
  ${CMAKE_SOURCE_DIR}/src/parser/jaguar.y
  ${CMAKE_SOURCE_DIR}/src/generated/parser.tab.cpp
)


# =========================
# LLVM
# =========================
#disable llvm warnings
if(MSVC)
  add_compile_options(/wd4624)
endif()

find_package(LLVM 20.1.8 REQUIRED CONFIG)

# =========================
# EXECUTABLE
# =========================
add_executable(Jaguar ressources/icon.rc
  ${BISON_JaguarParser_OUTPUTS}
  main.cpp

  #internal filesystem
  src/filesystem/filesystem.cpp

  #lexer
  src/lexer/lexer.cpp

  #internal logger
  src/logger/compile_time_logger.cpp

  #parser
  src/parser/parser.cpp
  src/parser/nodes/nodes.cpp

  #AST Nodes

  #common
  src/llvm/mng.cpp

  #JIT
  src/JIT/jit.cpp
)

target_include_directories(Jaguar PRIVATE src)


# =========================
# LINK LLVM
# =========================
target_include_directories(Jaguar PRIVATE ${LLVM_INCLUDE_DIRS})
llvm_map_components_to_libnames(llvm_libs
  Core
  Support
  ExecutionEngine
  OrcJIT
  X86
  X86CodeGen
  X86Desc
  X86AsmParser
  Target
  MC
  MCParser
)
target_link_libraries(Jaguar ${llvm_libs})