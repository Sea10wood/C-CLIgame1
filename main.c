#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "utils.h"
#include "window.h"

int main() {
    char username[50];
    printf("ユーザーネームを入力してください: ");
    scanf("%s", username);
    printf("こんにちは！%s！ゲームを始めるね！\n", username);

    if (create_window("Hi!!", 800, 600) != 0) {
        return 1; 
    }

    render_text("Hi!", 300, 250); 

    SDL_Event event;
    int running = 1;
    int continue_game = 0; 
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_Delay(100); 

        render_text("Hi!", 300, 250);

        if (continue_game == 0) {
            const char *continue_choices[] = {"Yes", "No"};
            continue_game = show_menu("続けますか？", continue_choices, 2);
        }

        if (continue_game == 1) {
            printf("ミッション1\n");
            printf("現在の作業ディレクトリを表示するコマンドは何でしょうか？\n");

            char user_input[50];
            while (1) {
                printf("コマンド: ");
                scanf("%s", user_input);

                if (strcmp(user_input, "pwd") == 0) {
                    char cwd[1024];
                    if (get_current_directory(cwd, sizeof(cwd)) != NULL) {
                        printf("あったり〜！現在のファイル位置は: %s\n", cwd);
                        break;
                    } else {
                        perror("getcwd() エラー");
                        return 1;
                    }
                } else {
                    const char *hint_choices[] = {"みせて！", "不要じゃ"};
                    int hint_choice = show_menu("ヒント、ほしい？", hint_choices, 2);

                    if (hint_choice == 1) {
                        printf("ヒント: 現在の作業ディレクトリを確認するコマンドは3文字の短い言葉です。\n");
                    } else {
                        printf("いいね、再チャレンジをどうぞ！\n");
                    }
                }
            }

            printf("\nミッション2\n");
            printf("ファイルのリストを表示するコマンドは何でしょうか？\n");

            while (1) {
                printf("コマンド: ");
                scanf("%s", user_input);

                if (strcmp(user_input, "ls") == 0) {
                    printf("あったり〜！ファイルのリストを表示するコマンドは: ls です。\n");
                    break;
                } else {
                    const char *hint_choices[] = {"みせて！", "不要じゃ"};
                    int hint_choice = show_menu("ヒント、ほしい？", hint_choices, 2);

                    if (hint_choice == 1) {
                        printf("ヒント: ファイルを一覧表示するコマンドは2文字です。\n");
                    } else {
                        printf("いいね、再チャレンジをどうぞ！\n");
                    }
                }
            }
        } else {
            printf("じゃあね\n");
            running = 0;
        }
    }

    destroy_window();
    return 0;
}
