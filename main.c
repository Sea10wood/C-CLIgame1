#include <stdio.h>
#include <string.h>
#include "question/question.h"
#include "salt/salt.h"
#include "window/window.h"
#include "error/error_EOC.h"
#include "mission/mission.h" 

int main() {
    char username[50];
    printf("ユーザーネームを入力してください: ");
    if (scanf("%s", username) == EOF) {
        handle_eof_error();
    }
    printf("こんにちは！%s！ゲームを始めるね！\n", username);

    if (create_window("Hi!!", 800, 600) != 0) {
        handle_error("ウィンドウの作成に失敗しました");
    }

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
            continue_game = show_question("続けますか？", continue_choices, 2);
        }

        if (continue_game == 1) {
            execute_mission1(); 
            execute_mission2(); 
        } else {
            printf("じゃあね\n");
            running = 0;
        }
    }

    destroy_window();
    return 0;
}
