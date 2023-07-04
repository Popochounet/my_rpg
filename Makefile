##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

SRC = 	src/main.c												\
		src/init_g_src.c										\
		src/menu.c												\
		src/menu_init.c											\
		src/settings.c											\
		src/resolution.c 										\
		src/core.c 												\
		src/pause_menu.c										\
		src/save_and_load.c 									\
		src/p_man_stats.c 										\
		src/p_man_inventory.c 									\
		src/weapon.c 											\
		src/event.c												\
		src/manage_mouse.c										\
		src/button.c											\
		src/sliding_button.c									\
		src/button_append.c										\
		src/button_interactions.c								\
		src/save.c												\
		src/free.c												\
		src/free_cop.c 											\
		src/free_weapon_sprite.c 								\
		src/crowd.c 											\
		src/progress_bar.c 										\
		src/rand.c												\
		src/init_crowd.c 										\
		src/update_cop.c 										\
		src/update_mob.c 										\
		src/update.c											\
		src/character_menu/character_menu.c						\
		src/character_menu/character_menu_init.c				\
		src/character_menu/character_menu_free.c				\
		src/character_menu/character_menu_shrink_window.c		\
		src/countryball_49_3/countryball.c						\
		src/countryball_49_3/countryball_free.c					\
		src/init_player.c										\
		src/stat_interface.c 									\
		src/stat_interface_init.c								\
		src/management_interaction.c							\
		src/hitbox.c											\
		src/speech_bubble/speech_bubble.c						\
		src/speech_bubble/speech_bubble_free.c					\
		src/speech_bubble/speech_bubble_linked_list.c			\
		src/speech_bubble/speech_bubble_resize_text_and_move.c	\
		src/scripts/edit_hitbox.c								\
		src/update_sheet.c										\
		src/restart.c											\
		src/init_cop.c 											\
		src/init_mob.c											\
		src/init_player_draw.c									\
		src/calculate.c											\
		src/win_pop_up/win_pop_up.c								\
		src/scripts/tuto.c										\
		src/scripts/my_function_part1.c							\
		src/scripts/my_function_part2.c

OBJ =   $(SRC:.c=.o)

CC  =   gcc
DEBUG   =   -g3 -p -ggdb3 -DDEBUG_MODE

# To prevent Marvin from flagging my code due to optimizations
RELEASE = -O0 -fno-builtin
SANITIZE	=	-fsanitize=address,undefined \
-fsanitize-recover=address,undefined
ANALYZER	=

CFLAGS  +=  -Wall -Wextra -pedantic -fsigned-char       \
-funsigned-bitfields -Wno-unused-parameter -std=gnu2x -fms-extensions
LDFLAGS	+=	-L ./lib -l graphics -l csfml-graphics \
-l csfml-window -l csfml-system -l csfml-audio -l button -l my -l audio -lm
LD_PRELOAD	=

NAME    =   my_rpg

.PHONY: all re
all: CFLAGS += $(RELEASE)
all: $(NAME)
re: fclean all

.PHONY: debug redebug
debug: CFLAGS += $(DEBUG)
debug: LIB_COMPILE += debug
debug: $(NAME)
redebug: fclean debug

.PHONY: sanitize resanitize
sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: LIB_COMPILE += sanitize
sanitize: LD_PRELOAD += -lasan -lubsan
sanitize: $(NAME)
resanitize: fclean sanitize

.PHONY: analyzer reanalyzer reset_analyzer
reset_analyzer:
	@rm -f analyzer.log
	@echo Removing old analyzer.log
analyzer: ANALYZER += on
analyzer: CFLAGS += $(DEBUG) -fanalyzer
analyzer: LIB_COMPILE += analyzer
analyzer: reset_analyzer $(NAME)
reanalyzer: fclean analyzer

.PHONY: make_libs
make_libs:
	@$(MAKE) -s -j -C lib/my/ $(LIB_COMPILE)
	@$(MAKE) -s -j -C lib/my_graphics $(LIB_COMPILE)
	@$(MAKE) -s -j -C lib/button $(LIB_COMPILE)
	@$(MAKE) -s -j -C lib/audio $(LIB_COMPILE)

$(NAME): make_libs $(OBJ)
	@echo -------------
	@echo CC : $(CC)
	@echo CFLAGS : $(CFLAGS)
	@echo LDFLAGS : $(LD_PRELOAD) $(LDFLAGS)
	@gcc $(OBJ) $(LD_PRELOAD) $(LDFLAGS) -o $(NAME)
	@if [[ "$(ANALYZER)" != "" ]]; then\
		echo "GCC Analyzer log in analyzer.log";\
	fi

%.o: %.c
	@if [[ "$(ANALYZER)" != "" ]]; then\
		$(CC) -c $(CFLAGS) $< -I ./include/ -o $@ 2>> analyzer.log;\
	else\
		$(CC) -c $(CFLAGS) $< -I ./include/ -o $@;\
	fi

.PHONY: clean_libs
clean_libs:
	@$(MAKE) -s -j -C ./lib/my/ clean
	@$(MAKE) -s -j -C ./lib/my_graphics clean
	@$(MAKE) -s -j -C ./lib/button clean
	@$(MAKE) -s -j -C ./lib/audio clean

.PHONY: clean
clean: clean_libs
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f vgcore.*
	@rm -f *.log
	@rm -f $(OBJ)

.PHONY: fclean_libs
fclean_libs:
	@$(MAKE) -s -j -C ./lib/my/ fclean
	@$(MAKE) -s -j -C ./lib/my_graphics fclean
	@$(MAKE) -s -j -C ./lib/button fclean
	@$(MAKE) -s -j -C ./lib/audio fclean

.PHONY: fclean
fclean: clean fclean_libs
	@rm -f $(NAME)
