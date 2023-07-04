##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	printf/apply_modifiers.c \
printf/call_flags.c \
printf/convert_floats.c \
printf/convert_pointers.c \
printf/convert_signed_integers.c \
printf/convert_strings.c \
printf/convert_unsigned_integers.c \
printf/flag_a.c \
printf/flag_a_core.c \
printf/flag_b.c \
printf/flag_c.c \
printf/flag_di.c \
printf/flag_e.c \
printf/flag_f.c \
printf/flag_g.c \
printf/flag_length.c \
printf/flag_n.c \
printf/flag_o.c \
printf/flag_p.c \
printf/flag_s.c \
printf/flag_u.c \
printf/flag_x.c \
printf/float_core.c \
printf/my_printf.c \
printf/my_wcalloc.c \
printf/my_wgetnbr.c \
printf/my_wgetnbr_core.c \
printf/my_wprintf2.c \
printf/my_wprintf.c \
printf/my_wputchar.c \
printf/my_wputnbr_base.c \
printf/my_wputstr.c \
printf/my_wstrcmp.c \
printf/my_wstrdup.c \
printf/my_wstring2.c \
printf/my_wstring.c \
printf/my_wstrlen.c \
printf/my_wstrstr.c \
printf/parser.c \
printf/parser_set.c \
printf/read_arg.c \
printf/wchar_traits.c \
printf/wstring_convert.c \
angle.c \
char_traits.c \
free_all.c \
is_between.c \
my_calloc.c \
my_compute_power_rec.c \
my_compute_square_root.c \
my_convert_nbr_base.c \
my_find_prime_sup.c \
my_getnbr.c \
my_get_nbr_core.c \
my_isdigit.c \
my_isneg.c \
my_is_prime.c \
my_isspace.c \
my_putchar.c \
my_put_nbr.c \
my_putstr.c \
my_revstr.c \
my_strcapitalize.c \
my_strcat.c \
my_strchr.c \
my_strcmp.c \
my_strcpy.c \
my_strdup.c \
my_string2.c \
my_string_append_str.c \
my_string.c \
my_str_isalpha.c \
my_strlen.c \
my_strlowcase.c \
my_strncat.c \
my_strncmp.c \
my_strncpy.c \
my_strstr.c \
my_str_to_word_array.c \
my_strupcase.c \
my_swap.c \
str_advance.c \
str_append.c \
str_array2.c \
str_array.c \
str_count.c \
str_count_str.c \
str_find.c \
str_find_not.c \
str_merge.c \
str_split.c

OBJ	=	$(SRC:.c=.o)

CC 	=	gcc
DEBUG	=	-g3 -p -ggdb3
# Prevents GCC optimizations
RELEASE =  -O0 -fno-builtin
SANITIZE	=	-fsanitize=address,undefined \
-fsanitize-recover=address,undefined
ANALYZER	=

CFLAGS	+=	-Wall -Wextra -pedantic -fsigned-char		\
-funsigned-bitfields -Wno-unused-parameter -std=gnu2x

NAME	=	../libmy.a

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
link_header: my.h
	@echo [LIB MY] Linking header my.h
	@ln -f my.h ../../include/my.h

$(NAME): link_header $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@if [[ "$(ANALYZER)" != "" ]]; then\
		echo "[LIB MY] GCC Analyzer log in analyzer.log";\
	fi

%.o: %.c
	@if [[ "$(ANALYZER)" != "" ]]; then\
		$(CC) -c $(CFLAGS) $< -I ../../include/ -o $@ 2>> analyzer.log;\
	else\
		$(CC) -c $(CFLAGS) $< -I ../../include/ -o $@;\
	fi

.PHONY: clean
clean:
	@echo "[LIB MY] Removing temporary and object files."
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f vgcore.*
	@rm -f *.log
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f ../$(NAME)

.PHONY: fclean
fclean: clean
	@echo "[LIB MY] Removing binary."
	@rm -f ../$(NAME)
