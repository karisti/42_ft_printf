# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 13:16:39 by karisti-          #+#    #+#              #
#    Updated: 2020/03/03 10:42:32 by karisti-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libftprintf.a
LIBFT_A 	=	libft.a

COMP 		=	gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H 	=	-I includes/
LIBFT_H 	= 	-I srcs/libft/includes

OBJ_DIR 	=	obj/
SRC_DIR 	=	srcs/
LIB_DIR 	=	srcs/libft/

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

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory

$(NAME): $(OBJ_DIR) $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

test:
	gcc -g -Wall -Werror -Wextra srcs/*.c srcs/libft/srcs/*.c -I includes/ -I srcs/libft/includes && clear && ./a.out

.PHONY: all clean flcean re