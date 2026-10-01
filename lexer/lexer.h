#ifndef BRN_LEXER_H
#define BRN_LEXER_H

#include <stddef.h>
#include "../token/token.h"

typedef struct {
    const char *source;

    size_t position;
    size_t length;

} Lexer;

void LexerInit(Lexer *lexer, const char *source);
Token LexerNextToken(Lexer *lexer);

#endif