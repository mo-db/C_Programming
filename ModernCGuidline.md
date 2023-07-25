# Compiler
- binary code is platform dependent
- C exests to provide an abstraction layer for all different
    machine-specific languages (assembler languages)



# Statements
- *Iteration* loop, for
- *function calls*
- *return statement*x

## 5 conditional control statements
- if, for, do, while, switch (and some advanced others)



# Miniaudio API
- links to frameworkes like Coreaudio at runtime? *what that?*
- interesting line: *A_SUPPORT_COREAUDIO*



# Coreaudio
- Lowest is *AUDIO UNITS*



# Basic values and data
## pre
- Portable code should be about values and not representations
anmerkung anmerkung ...

## the abstract state machine
- *value* (what state are we in?)
    all values are numbers
- *type* (wat this state represents)
    - all values have a type
    - possible operations on a value are determined by its
        type
    - a value's type determines the results of all 
        operations
anmerkung anmerkung ...
- *representation* (how the state is destinguished)
    - a types *binary representation* determines the result
        of all operations
    - a types *object representation* completely determines
        how values are stored in memory or on disk
- the slackness between program description and abstract
    state machine is referred to as *optimization*
- type determines optimization opportunities
anmerkung anmerkung ... what now is an abstract state machine?

## Basic types
- two levels of types:
    first level things like 'signed', 'int', ...
    second level types from header files like 'size_t', 'bool', ...
- first level: 2 classes with 2 subclasses
    *unsigned int*, *signed int*
    *real float*, *complex float*
    - each of these *classes* contains several *types* (18) that differ according
        to their precision
    - there are 6 *narrow types* that can't be used for arithmetic and will
        be 'promoted' to *signed int* bevore arithmetic:
            unsigned/signed char and short
    - C standard *doesn't prescribe* the percision of the 12 remaining types
        it only constrains them: they must *include each other according to*
        *their rank*
    - the *unsigned type* has values that do not fit into the *signed type*
        maximal values is 2^31 −1 = 2147483647 for signed int and 
        2^32 −1 = 4294967295 for unsigned int.

# Specifying values
- *decimal integer constant*: 123
- *decimal float constant*: 1.94
- *decimal float constants scientific*: 1.7E-13 means 1.7 * 10^-13

- *octal integer constant*: 077
    - starts with 0 and then digits from 0-7, 077 is 63
    - not commonly used
- *hexadecimal integer constant*: 0xFFFF
    - starts with 0x antd then digits from 0-9 and a-f 
    - 16_10 is 10_16 and 31_10 is 1F_16
- *hexadecimal floating-point constants*: 0x2.7aP3
    - in decimal: 2 + 0.3125 + 0.0390625 * 2^3
    - the component after P is specified decimal
- *numerical literals are never negative*
    - for someting like -34 the leading sign is not considered part
        of the number but is the negation operator


# Pointers



# Arrays
