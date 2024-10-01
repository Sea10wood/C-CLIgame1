#include "error_EOC.h"
#include <stdio.h>

void handle_eof_error() {
    printf("EOFエラーが発生しました。\n");
}

void handle_error(const char *msg) {
    printf("エラー: %s\n", msg);
}
