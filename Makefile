# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 13:16:39 by karisti-          #+#    #+#              #
#    Updated: 2023/11/03 19:52:07 by karisti-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libftprintf.a
LIBFT_A 	=	libft.a

COMP 		=	gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H 	=	-I includes/
LIBFT_H 	= 	-I libft/includes

OBJ_DIR 	=	bin/obj/
SRC_DIR 	=	srcs/
LIB_DIR 	=	libft/
LIB_BIN		=	$(LIB_DIR)/bin/
BIN				=	bin/

CFILE		=	ft_printf.c \
				ft_placeholder.c \
				ft_arguments.c \
				ft_manage_utils.c \
				ft_manage_c.c \
				ft_manage_s.c \
				ft_manage_nbr.c \
				ft_manage_p.c \
				ft_manage_per.c \
				ft_manage_x.c

CFIND 		=	$(CFILE:%=$(SRC_DIR)%)

OFILE 		=	$(CFILE:%.c=%.o)

OBJ 		=	$(addprefix $(OBJ_DIR), $(OFILE))

# Colors
RED		=	\033[0;31m
GREEN	=	\033[0;32m
NONE	=	\033[0m
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(NAME): $(OBJ_DIR) $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_BIN)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo "\t[ $(RED)✗$(NONE) ] ft_printf Objects directory"

fclean: clean
		@/bin/rm -rf $(BIN)
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo "\t[ $(RED)✗$(NONE) ] Cleaned $(NAME) library"

re: fclean all

test:
	gcc -g -Wall -Werror -Wextra srcs/*.c srcs/libft/srcs/*.c -I includes/ -I srcs/libft/includes && clear && ./a.out

.PHONY: all clean flcean re
