CC := gcc

CFLAGS := $(shell pkg-config libpq --cflags)

SRCDIR := src/
OBJDIR := build/obj/

NAME := agias

SFILES := c
OFILES := o

LIBS := $(shell pkg-config libpq --libs)

SOURCES := $(shell find $(SRCDIR) -name "*.$(SFILES)")
OBJECTS := $(patsubst $(SRCDIR)%.$(SFILES), $(OBJDIR)%.$(OFILES), $(SOURCES))




all: $(NAME)


$(NAME): $(OBJECTS)
	$(CC) $^ $(LIBS) -o $@

$(OBJDIR)%$(OFILES): $(SRCDIR)%$(SFILES)
	$(CC) $(CFLAGS) -c $< -o $@

