NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
AR = ar rcs
RM = rm -f

BUILD_DIR = build

# Source directories
LIBFT_DIR = src/libft_core
GNL_DIR = src/get_next_line/src
EXTRA_DIR = src/libft_extra
FT_PRINTF_DIR = src/ft_printf/src

# File lists
LIBFT_FILES = ft_atoi ft_bzero ft_calloc ft_isalpha ft_isalnum \
	ft_isascii ft_isdigit ft_isprint ft_memchr ft_memcmp \
	ft_memcpy ft_memmove ft_memset ft_strchr ft_strcpy ft_strdup \
	ft_strlcat ft_strlcpy ft_strlen ft_strncmp ft_strnstr \
	ft_strrchr ft_tolower ft_toupper ft_substr ft_strjoin \
	ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	ft_iswhitespace

GNL_FILES = get_next_line
EXTRA_FILES = error_exit safe_malloc word_count
FT_PRINTF_FILES = ft_printf ft_print

# Full paths to .c files
SRCS = $(addprefix $(LIBFT_DIR)/, $(addsuffix .c, $(LIBFT_FILES))) \
	   $(addprefix $(GNL_DIR)/, $(addsuffix .c, $(GNL_FILES))) \
	   $(addprefix $(EXTRA_DIR)/, $(addsuffix .c, $(EXTRA_FILES))) \
	   $(addprefix $(FT_PRINTF_DIR)/, $(addsuffix .c, $(FT_PRINTF_FILES)))

# Map each .c to a build/*.o
OBJS = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.c=.o)))

# Pattern rule: match .c source based on object filename
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# This rule ensures we pass the correct full path to the compiler
$(BUILD_DIR)/%.o: $(LIBFT_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/%.o: $(GNL_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/%.o: $(EXTRA_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/%.o: $(FT_PRINTF_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Make sure build/ exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build the static library
$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
