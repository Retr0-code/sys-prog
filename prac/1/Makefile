CC = gcc
CFLAGS = -Wall
BUILDDIR = .build/
TARGET = $(BUILDDIR)program
SRCS = src/
OBJS=$(patsubst $(SRCS)%.c, $(BUILDDIR)%.o, $(wildcard $(SRCS)*.c))

all: checkbuild $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(BUILDDIR)%.o: $(SRCS)%.c
	$(CC) $(CFLAGS) -c $< -o $@

checkbuild:
	./checkbuild.sh

clean:
	rm -rf $(BUILDDIR)*
