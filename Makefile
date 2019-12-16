CC = g++
CFLAGS = -std=c++17
CSANIT = -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -O2 -g
TFLAGS = -pthread -pedantic -Dcimg_use_vt100 -Dcimg_display=1   -lm -lX11 -lpthread
NAMEFILE = launcher.cpp
NAMEFILETEST = ./test/AllTests.cpp

CCM = c++
COFLAGS = -I.. -Wall -std=c++17  -Dcimg_use_vt100 -Dcimg_display=1 -I/usr/X11R6/include -lm -L/usr/X11R6/lib -lX11 -lpthread

linux:
	$(CC)  $(CFLAGS) $(NAMEFILE) $(TFLAGS) -o main.o && ./main.o
macosx:
	$(CCM) $(COFLAGS) $(NAMEFILE)  -o main.o && ./main.o
test-code:
	$(CC) -DTEST $(CFLAGS) $(NAMEFILETEST) -o main.o && ./main.o
debug:
	$(CC) -DDEBUG  $(CFLAGS) $(NAMEFILE) $(TFLAGS) -o main.o && ./main.o
