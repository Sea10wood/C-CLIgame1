CC = gcc

TARGET = game

SRC = main.c window/window.c question/question.c question/hash/hash.c salt/salt.c error/error_EOC.c mission/mission.c

INCLUDES = -I/opt/homebrew/Cellar/sdl2/2.30.7/include \
           -I/opt/homebrew/Cellar/sdl2/2.30.7/include/SDL2 \
           -I/opt/homebrew/opt/sdl2_ttf/include \
           -I/opt/homebrew/opt/openssl@3/include \
           -Iwindow \
           -Iquestion \
           -Iquestion/hash \
           -Isalt \
           -Ierror \
           -Imission \
           -I.

LDFLAGS = -L/opt/homebrew/Cellar/sdl2/2.30.7/lib \
          -L/opt/homebrew/opt/sdl2_ttf/lib \
          -L/opt/homebrew/opt/openssl@3/lib

LIBS = -lSDL2 -lSDL2_ttf -lssl -lcrypto

CFLAGS = $(INCLUDES)

LFLAGS = $(LDFLAGS) $(LIBS)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(TARGET)
