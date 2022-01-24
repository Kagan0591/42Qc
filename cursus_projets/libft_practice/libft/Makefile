SRCS_FILES 	= ft_lstnew_2.c \
			ft_lstsize_1.c \
			ft_lstadd_front_1.c \
			ft_lstlast_1.c \
			ft_lstadd_back_1.c \
			ft_lstdelone_1.c \
			ft_lstclear_1.c \
			ft_lstiter_1.c \
			ft_lstmap_1.c \

NAME = libft.a
OBJS = $(SRCS_FILES:.c=.o)
CC = gcc
FLAGS = -Wall -Werror -Wextra
ARCHIVE = ar -crs
REMOVE = rm -rf
SRCS_DIR = ./
### Colour variables ###
END			= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
URL			= \033[4m
BLINK		= \033[5m
BLINK2		= \033[6m
SELECTED	= \033[7m

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
VIOLET		= \033[35m
BEIGE		= \033[36m
WHITE		= \033[37m

all: ${NAME}

${NAME}: ${OBJS}
	@${ARCHIVE} ${NAME} ${OBJS}
	@echo "${OBJS} ${GREEN}${BOLD}\n\nObjects files are added to the archive libft.a correctly\n${END}"

.c.o:
	$(CC) ${FLAGS} -o $@ -c $<
	@echo "${GREEN}Compilation OK!${END}"

clean:
	$(REMOVE) ${OBJS}
	@echo "\n${GREEN}${BOLD}Objects files are deleted correcly\n${END}"

fclean: clean
	@${REMOVE} ${NAME}
	@echo "\n${GREEN}${BOLD}Library are deleted too\n${END}"

re: fclean all
	@echo "${GREEN}${BOLD}Library are remaked correcly${END}"
