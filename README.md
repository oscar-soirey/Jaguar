# Introduction
The Jaguar programming language is a multiplatform powerful object-oriented programming language.


# Compile Jaguar Compiler
## Note
The Jaguar compiler was compiled using CLion IDE on windows, if you also want to modify or (and) compile it, I recommend you to use CLion.

## Dependencies
---
### Bison
Bison is used for build the AST of the program.

- Bison is a third party library, you do need it to compile the Jaguar compiler.
- Please install it from MSYS2 UCRT terminal, see https://thejaguarlanguage.com for more informations.

---

### LLVM
LLVM is used for generate intermediate representation of jaguar file and to compile it.

Compiler (mandatory) : MSVC 2022 (the latest version if possible)
Jaguar use the 20.1.8 version of LLVM

If you want to update to a newer version, you can download it from https://github.com/vovkos/llvm-package-windows/releases .
You will need :
- `llvm-20.1.8-windows-amd64-msvc17-msvcrt-dbg.7z` for debug mode.
- `llvm-20.1.8-windows-amd64-msvc17-msvcrt.7z` for release mode.

---

### CMAKE Config
Mandatory Cmake options : 
```cmake
-DLLVM_DIR="C:/path/to/llvm(-debug or -release)/lib/cmake/llvm"
```

Use the `llvm-debug` for debug cmake profile and `llvm-release` for release profile

---

## Installer

### Windows
The Jaguar installer uses Inno Setup Compiler, the inno project can be found at `installer/inno_jaguar_installer.iss`.
You can open it using the latest version of Inni Setup Compiler at https://jrsoftware.org/isdl.php

### MacOS

### Linux


# Use compiler API
The jaguar compiler has a C-API for project integration, it uses one header file and one precompiled static library.
You can use it to build intelisense, IDEs and others.