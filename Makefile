CC = gcc
CFLAGS = -g -Wall
OBJFILES = P0.o tree.o
TARGET = P0

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CLFAGS) -o $(TARGET) $(OBJFILES) 
	
clean:
	$(RM) $(OBJFILES) $(TARGET) *.preorder *.inorder *.postorder temptext.txt