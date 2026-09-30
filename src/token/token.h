#ifndef BRN_TOKEN_H
#define BRN_TOKEN_H

#include <stddef.h>

typedef enum {
    TOKEN_EOF,
    TOKEN_UNKNOWN,

    TOKEN_IDENTIFIER,
    TOKEN_STRING,
    TOKEN_INTEGER,
    TOKEN_FLOAT,

    TOKEN_VAR,
    TOKEN_FUNC,
    TOKEN_IF,
    TOKEN_LOOP,
    TOKEN_END,
    TOKEN_AS,
    TOKEN_RETURN,
    TOKEN_CONST,

    TOKEN_TYPE_STR,
    TOKEN_TYPE_INT,
    TOKEN_TYPE_FLOAT,
    TOKEN_TYPE_BOOL,
    TOKEN_TYPE_CHAR,
    TOKEN_TYPE_UNIQUE,
    TOKEN_TYPE_NONE,

    TOKEN_EQUAL,
    TOKEN_EQUAL_EQUAL,
    TOKEN_NOT_EQUAL,
    TOKEN_MODULO,
    TOKEN_OR,
    TOKEN_EXPLICIT,

    TOKEN_COLON,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_ARROW
    
} Token_type;  

typedef struct {
    Token_type type;
    const char *lexeme;
    size_t length;
    
} Token;

const char *TokenTypeName(Token_type type);

#endif