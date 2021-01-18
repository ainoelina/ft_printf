# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avuorio <avuorio@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/07 11:28:19 by avuorio       #+#    #+#                  #
#    Updated: 2021/01/18 12:28:56 by avuorio       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS_LIST		=	ft_printf.c \
					parse_format.c \
					handle_conversion.c \
					handle_int.c handle_char.c \
					pf_process_output.c \
					pf_atoi_printf.c \
					pf_itoa_printf.c pf_itoa_base.c \
					pf_utils.c pf_helpers.c

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

LIBFT 			= libft

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@echo "\033[38;5;33mcompiling project: \033[0m"
				@make -C $(LIBFT)
				@echo "\033[38;5;37mcreating libftprintf ... \033[0m"
				@cp libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJS}
				@echo "\033[38;5;38mlibftprintf created!\033[0m"
				@echo "\033[38;5;51mmake succesful! :-)\033[m"

bonus:			${NAME}
				@echo "\033[38;5;39mmaking with bonus files ... \033[0m"
				@echo "\033[38;5;27mmake bonus succesful! :-) \033[0m"

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)
				@echo "\033[38;5;154mclean object files \033[0m"

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)
				@echo "\033[38;5;154mclean executable \033[0m"

re:				fclean all
				@echo "\033[38;5;155mclean object files \033[0m"

.PHONY: 		all fclean clean re
