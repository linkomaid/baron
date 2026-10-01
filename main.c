#include <stdio.h>

#include "lexer/lexer.h"
#include "token/token.h"

int main(void)
{
    const char *source =
        "var boo @ // hahahaha";

    Lexer lexer;
    LexerInit(&lexer, source);

    Token token;

    do
    {
        token = LexerNextToken(&lexer);

        printf("%s", TokenTypeName(token.type));

        if (token.length > 0)
            printf(" -> %.*s", (int)token.length, token.lexeme);

        printf("\n");

    } while (token.type != TOKEN_EOF);

    return 0;
}