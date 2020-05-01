# kencc-cross
Updated Plan9 cross compilers (for OSX <= 10.14 and Linux) including RISC V target

* ken-cc compilers based on aryx' fork: https://github.com/aryx/fork-kencc
* RISC V compiler by Richard Miller: https://9p.io/sources/contrib/miller/riscv.tar

    0c spim    little-endian MIPS 3000 family
    1c 68000   Motorola MC68000
    2c 68020   Motorola MC68020
    5c arm     little-endian ARM
    6c amd64   AMD64 and compatibles (e.g., Intel EM64T)
    7c arm64   little-endian ARM64
    8c 386     Intel i386, i486, Pentium, etc.
    kc sparc   Sun SPARC
    qc power   Power PC
    tc arm     little-endian ARM THUMB
    uc sparc64 SPARC64
    vc mips    big-endian MIPS 3000 family
    zc riscv   RISC V

