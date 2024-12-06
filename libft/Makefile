Library = libft

files = ft_strlen \
        ft_memmove \
        ft_memcpy \
        ft_strlcpy \
        ft_strlcat \
        ft_isalpha \
        ft_isdigit \
        ft_isalnum \
        ft_isascii \
        ft_isprint \
        ft_memset \
        ft_bzero \
        ft_toupper \
        ft_tolower \
        ft_strchr \
        ft_strrchr \
        ft_strncmp \
        ft_memchr \
        ft_memcmp \
        ft_strnstr \
        ft_atoi \
        ft_calloc \
        ft_strdup \
        ft_substr \
        ft_strjoin \
        ft_strtrim \
        ft_split \
        ft_itoa \
        ft_strmapi \
        ft_striteri \
        ft_putchar_fd \
        ft_putstr_fd \
        ft_putendl_fd \
        ft_putnbr_fd \
	
BONUS_SRC = ft_lstadd_back \
            ft_lstadd_front \
            ft_lstclear \
            ft_lstdelone \
            ft_lstiter \
            ft_lstlast \
            ft_lstmap \
            ft_lstnew \
            ft_lstsize

Compiler = cc
CmpFlags = -Wall -Wextra -Werror

OUTN = $(Library).a

OFILES = $(files:%=%.o)
BONUS_OBJ = $(BONUS_SRC:%=%.o)

NAME = $(OUTN)

$(NAME): $(OFILES)
	ar -rc $(OUTN) $(OFILES)
	ranlib $(OUTN)

all: $(NAME)

bonus: $(OFILES) $(BONUS_OBJ)
	ar -rc $(OUTN) $(OFILES) $(BONUS_OBJ)
	ranlib $(OUTN)

clean:
	rm -f $(OFILES) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
