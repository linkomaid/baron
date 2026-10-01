#include "token.h"

const char *TokenTypeName(Token_type type) {
    switch(type) {
        case TOKEN_EOF:             return "EOF";
        case TOKEN_UNKNOWN:         return "UNKNOWN";

        case TOKEN_IDENTIFIER:      return "IDENTIFIER";
        case TOKEN_STRING:          return "STRING";
        case TOKEN_INTEGER:         return "INTEGER";
        case TOKEN_FLOAT:           return "FLOAT";

        case TOKEN_VAR:             return "VAR";
        case TOKEN_FUNC:            return "FUNC";
        case TOKEN_IF:              return "IF";
        case TOKEN_LOOP:            return "LOOP";
        case TOKEN_END:             return "END";
        case TOKEN_AS:              return "AS";
        case TOKEN_RETURN:          return "RETURN";
        case TOKEN_CONST:           return "CONST";
        case TOKEN_PACK:            return "PACK";
        case TOKEN_UNPACK:          return "UNPACK";
        case TOKEN_EXPORT:          return "EXPORT";

        case TOKEN_TYPE_STR:        return "TYPE_STR";
        case TOKEN_TYPE_INT:        return "TYPE_INT";
        case TOKEN_TYPE_FLOAT:      return "TYPE_FLOAT";
        case TOKEN_TYPE_BOOL:       return "TYPE_BOOL";
        case TOKEN_TYPE_CHAR:       return "TYPE_CHAR";
        case TOKEN_TYPE_UNIQUE:     return "TYPE_UNIQUE";
        case TOKEN_TYPE_NONE:       return "TYPE_NONE";
        case TOKEN_TYPE_ANY:        return "TYPE_ANY";
        case TOKEN_TYPE_LIST:       return "TYPE_LIST";
        case TOKEN_TYPE_DICT:       return "TYPE_DICT";
        case TOKEN_TYPE_TUPLE:      return "TYPE_TUPLE";
        case TOKEN_TYPE_ARRAY:      return "TYPE_ARRAY";
        case TOKEN_TYPE_JSON:       return "TYPE_JSON";
        case TOKEN_TYPE_SET:        return "TYPE_SET";
        case TOKEN_TYPE_OBJECT:     return "TYPE_OBJECT";
        case TOKEN_TYPE_BLOB:       return "TYPE_BLOB";

        case TOKEN_EQUAL:           return "EQUAL";
        case TOKEN_EQUAL_EQUAL:     return "EQUAL_EQUAL";
        case TOKEN_NOT_EQUAL:       return "NOT_EQUAL";
        case TOKEN_MODULO:          return "MODULO";
        case TOKEN_OR:              return "OR";
        case TOKEN_EXPLICIT:        return "EXPLICIT";
        case TOKEN_NULL_COALESCE:   return "NULL_COALESCE";

        case TOKEN_COLON:           return "COLON";
        case TOKEN_LBRACE:          return "LBRACE";
        case TOKEN_RBRACE:          return "RBRACE";
        case TOKEN_LBRACKET:        return "LBRACKET";
        case TOKEN_RBRACKET:        return "RBRACKET";
        case TOKEN_LPAREN:          return "LPAREN";
        case TOKEN_RPAREN:          return "RPAREN";
        case TOKEN_ARROW:           return "ARROW";
        case TOKEN_AT:              return "AT";
        case TOKEN_DOLLAR:          return "DOLLAR";
        case TOKEN_HASH:            return "HASH";
        case TOKEN_DOT:             return "DOT";

    }

    return "UNKNOWN";
}