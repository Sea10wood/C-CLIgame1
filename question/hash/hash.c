#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "hash.h"
#include "utils.h"

void get_hashed_answer(const char *answer, char *hashed_result) {
    char *salt = get_salt_from_env();
    char combined[256];
    snprintf(combined, sizeof(combined), "%s%s", salt, answer);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)combined, strlen(combined), hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashed_result + (i * 2), "%02x", hash[i]);
    }
}
