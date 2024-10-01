#include "mission.h"
#include "error/error_EOC.h"
#include "salt/salt.h"
#include "question/question.h"
#include <string.h>

void execute_mission1() {
    printf("ミッション1\n");
    printf("現在の作業ディレクトリを表示するコマンドは何でしょうか？\n");

    char user_input[50];
    while (1) {
        printf("コマンド: ");
        if (scanf("%s", user_input) == EOF) {
            handle_eof_error();
        }

        if (strcmp(user_input, "pwd") == 0) {
            char cwd[1024];
            if (get_current_directory(cwd, sizeof(cwd)) != NULL) {
                printf("あったり〜！現在のファイル位置は: %s\n", cwd);
                break;
            } else {
                handle_error("getcwd() エラー");
            }
        } else {
            const char *hint_choices[] = {"みせて！", "不要じゃ"};
            int hint_choice = show_question("ヒント、ほしい？", hint_choices, 2);

            if (hint_choice == 1) {
                printf("ヒント: 現在の作業ディレクトリを確認するコマンドは3文字の短い言葉です。\n");
            } else {
                printf("いいね、再チャレンジをどうぞ！\n");
            }
        }
    }
}

void execute_mission2() {
    printf("\nミッション2\n");
    printf("ファイルのリストを表示するコマンドは何でしょうか？\n");

    char user_input[50];
    while (1) {
        printf("コマンド: ");
        if (scanf("%s", user_input) == EOF) {
            handle_eof_error();
        }

        if (strcmp(user_input, "ls") == 0) {
            printf("あったり〜！ファイルのリストを表示するコマンドは: ls です。\n");
            break;
        } else {
            const char *hint_choices[] = {"みせて！", "不要じゃ"};
            int hint_choice = show_question("ヒント、ほしい？", hint_choices, 2);

            if (hint_choice == 1) {
                printf("ヒント: ファイルを一覧表示するコマンドは2文字です。\n");
            } else {
                printf("いいね、再チャレンジをどうぞ！\n");
            }
        }
    }
}
