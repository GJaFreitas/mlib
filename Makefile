COMPILER	= clang

CFLAGS		= -Wall -Wextra -g

NAME		= mylib.a

INCLUDE		= -Iinclude

AR		= ar rc

RANLIB		= ranlib

SRCS		:= $(shell find src -name "*.c" -type f)

SRC_NAMES	:= $(notdir $(SRCS))

OBJS		:= $(addprefix obj/,$(SRC_NAMES:.c=.o))

SRC_DIRS	:= $(sort $(dir $(SRCS)))

VPATH := $(SRC_DIRS)

all: $(NAME)

srcs:
	@echo srcs: $(SRCS)

obj/%.o: %.c | obj
	@$(COMPILER) -c $(INCLUDE) $(CFLAGS) $< -o $@

obj:
	@mkdir -p obj

$(NAME): $(OBJS)
	@echo "Creating library $@"
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)
	@echo "Library created successfully"

clean:
	@rm -rf obj
	@rm -f $(NAME)
	@echo "Cleaned"

re: clean all

.PHONY: all srcs clean re
