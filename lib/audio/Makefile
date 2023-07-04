##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	= \
audio_init.c \
audio_free.c \
audio_volume.c \
audio_set.c \
audio_control.c

OBJ	=	$(SRC:.c=.o)

CC 	=	gcc
DEBUG	=	-g3 -p -ggdb3
# Prevents GCC optimizations
RELEASE =  -O0 -fno-builtin
SANITIZE	=	-fsanitize=address,undefined \
-fsanitize-recover=address,undefined
ANALYZER 	=

CFLAGS	+=	-Wall -Wextra -pedantic -fsigned-char		\
-funsigned-bitfields -Wno-unused-parameter -std=gnu2x -pedantic

NAME	=	../libaudio.a

.PHONY: all re
all: CFLAGS += $(RELEASE)
all: $(NAME)
re: fclean all

.PHONY: debug redebug
debug: CFLAGS += $(DEBUG)
debug: $(NAME)
redebug: fclean debug

.PHONY: sanitize resanitize
sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: $(NAME)
resanitize: fclean sanitize

.PHONY: analyzer reanalyzer
analyzer: ANALYZER += on
analyzer: CFLAGS += $(DEBUG) -fanalyzer
analyzer: $(NAME)
reanalyzer: fclean analyzer

.PHONY: link_header
link_header: audio.h
	@echo [LIB AUDIO] Linking header audio.h
	@ln -f audio.h ../../include/audio.h

$(NAME): link_header $(OBJ)
	@echo Building lib button...
	@ar rcs $(NAME) $(OBJ)
	@if [[ "$(ANALYZER)" != "" ]]; then\
		echo "[LIB AUDIO] GCC Analyzer log in analyzer.log";\
	fi

%.o: %.c
	@if [[ "$(ANALYZER)" != "" ]]; then\
		$(CC) -c $(CFLAGS) $< -I ../../include/ -o $@ 2>> analyzer.log;\
	else\
		$(CC) -c $(CFLAGS) $< -I ../../include/ -o $@;\
	fi

.PHONY: clean
clean:
	@echo "[LIB AUDIO] Removing temporary and object files."
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f vgcore.*
	@rm -f *.log
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f ../$(NAME)

.PHONY: fclean
fclean: clean
	@echo "[LIB AUDIO] Removing binary."
	@rm -f ../$(NAME)
