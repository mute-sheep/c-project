CC := gcc
CFLAGS := -Wall -Wextra -g -std=c17
TARGET := reborn_c
SRCS := main.c file.c menu.c list.c str.c utile.c
OBJS := $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
