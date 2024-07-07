# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 13:40:12 by fvastena          #+#    #+#              #
#    Updated: 2024/07/05 11:32:10 by fvastena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
RMF = rm -f
RMD = rm -rf
HDDIR = -Iincludes

#          ----------========== {     SRCS     } ==========----------

# Characters
SRCS 	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_isblank.c ft_iscntrl.c ft_isgraph.c ft_ispunct.c ft_isspace.c \
			ft_isupper.c ft_islower.c ft_isxdigit.c \

# Mem
SRCS	+=	ft_memchr.c ft_memcmp.c ft_memmove.c ft_memcpy.c \
			ft_memset.c ft_bzero.c\

# Strings
SRCS	+=	ft_atoi.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \

# Advanced Strings
SRCS	+=	ft_calloc.c ft_strdup.c  ft_strndup.c \
			ft_itoa.c ft_split.c ft_strjoin.c ft_strtrim.c ft_substr.c \
			ft_striteri.c ft_strmapi.c \

SRCS	+=	ft_free_str.c ft_free_strs_tab.c ft_free_str_return.c ft_free_strs_tab_return.c \

# Lists
SRCS	+=	ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c ft_lstlast.c \
			ft_lstnew.c ft_lstsize.c ft_lstiter.c \
			ft_lstmap.c

# Get_next_line
SRCS	+=	get_next_line.c get_next_line_utils.c \

# Printing
SRCS	+=	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \

# ft_pintf
SRCS	+=	ft_printf.c ft_printf_utils.c ft_print_c.c ft_print_cx.c ft_print_d.c ft_print_i.c \
			ft_print_p.c ft_print_prct.c ft_print_s.c ft_print_u.c ft_print_x.c \


#          ----------========== {     OBJS     } ==========----------

SRCS_DIR = srcs/
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

VPATH = $(shell find $(SRCS_DIR) -type d)

#           ----------========== {    RULES    } ==========----------

all: $(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@printf "\n$(GREEN)$(NAME) created!$(DEFAULT)\n"

$(OBJS_DIR)%.o:	%.c
	@$(CC) $(CFLAGS) $(HDDIR) -c $< -o $@
	@printf "$(GREEN)Compiled: $< %-30s\r$(DEFAULT)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@$(RMF) $(OBJS)
	@$(RMD) $(OBJS_DIR)
	@printf "$(YELLOW)object files for $(NAME) deleted!$(DEFAULT)\n"

fclean:	clean
	@$(RMF) $(NAME)
	@printf "$(RED)$(NAME) deleted!$(DEFAULT)\n"

re:	fclean all

.PHONY:	all clean fclean re 

#           ----------========== {    COLORS    } ==========----------

RED = \033[1;31m
GREEN = \033[1;32m
GREEN_BG = \033[1;42m
YELLOW = \033[1;33m
DEFAULT = \033[0m