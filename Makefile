# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rhorbach <rhorbach@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 12:49:02 by rhorbach      #+#    #+#                  #
#    Updated: 2023/05/22 12:02:42 by rhorbach      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADERFILES = src/push_swap.h
NORMFLAGS = -Wall -Wextra -Werror $(if $(DEBUG),-g -fsanitize=address)
INCLUDES = $(addprefix -I, $(sort $(dir $(HEADERFILES))))
OBJDIR = obj
FILES = \
	src/push_swap.c					\
	src/radix_sort.c				\
	src/pre_sort.c					\
	src/operations.c				\
	src/i_list/ps_lstadd_back.c		\
	src/i_list/ps_lstadd_front.c	\
	src/i_list/ps_lstclear.c		\
	src/i_list/ps_lstlast.c			\
	src/i_list/ps_lstnew.c			\
	src/i_list/ps_lstnew_back.c		\
	src/i_list/ps_lstnew_front.c	\
	src/i_list/ps_lstsize.c

OBJFILES = $(addprefix $(OBJDIR)/,$(FILES:c=o))

LIBFT = ./libft/libft.a

HEADERFILES += ./libft/libft.h
LIBFLAGS = -L$(dir $(LIBFT)) -lft

clear_line = \e[K
move_up = \e[A
define prettycomp
printf "$(1)$(clear_line)\n"
$(1)
printf "$(move_up)"
endef

all: $(NAME)

$(NAME): $(OBJFILES) $(LIBFT)
	$(CC) $(NORMFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJFILES) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(dir $(LIBFT))

$(OBJDIR)/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	@$(call prettycomp,$(CC) -c $(NORMFLAGS) $(INCLUDES) $< -o $@)

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(dir $(LIBFT)) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(dir $(LIBFT)) fclean

re: fclean all

# bonus:
# 	$(MAKE) all BONUS=1


ifdef DEBUG
test: $(NAME)
	$(CC) $(NORMFLAGS) main.c -L. -l ftprintf -o DEBUG_ft_printf
else
test:
	$(MAKE) test DEBUG=1
endif

.PHONY: all clean fcleam re test bonus
