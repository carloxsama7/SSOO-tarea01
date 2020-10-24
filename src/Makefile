#makefile profesor
CC=gcc
CXX=gcc
RM=rm -f

TARGET=../hora

LDFLAGS=-L/usr/local/lib 

LDLIBS=-lpthread

CXXFLAGS= -g -Wall

DIR_OBJ=objs

SRCS=$(wildcard *.c)

OBJS=$(patsubst %.c,$(DIR_OBJ)/%.o,$(SRCS))


all: $(TARGET)
	@echo Made [ $? ] OK :\)

$(TARGET): $(OBJS)
	@echo Linking [$@]
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS) 

$(DIR_OBJ)/%.o: %.c
	@echo Compiling [$@]
	@mkdir -p $(DIR_OBJ)
	@$(CXX) -c -o $@ $< $(CXXFLAGS) 

clean:
	@$(RM) $(OBJS)
	@$(RM) *~ core

distclean: clean
	@$(RM) $(TARGET)
	@$(RM) -f $(DIR_OBJ)

.PHONY: all clean distclean
	
