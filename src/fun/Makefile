CC = gcc 
RM = rm -f
#CPPFLAGS = -DDEBUG=1
CPPFLAGS = -g -I.
CFLAGS = -O
LDFLAGS = -L.
LIBS =  -lfun -lm
OEXT = .o
EEXT =
SLEXT = .a
AR = ar rcs
TARGET=testlibfun
LOBJ = functions$(OEXT) plot$(OEXT) data$(OEXT)
all: libfun$(SLEXT) $(TARGET)$(EEXT)

$(TARGET)$(OEXT):
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(TARGET).c

$(TARGET)$(EEXT): libfun$(SLEXT) $(TARGET)$(OEXT)
	$(CC) $(LDFLAGS) $(CFLAGS) $(TARGET)$(OEXT)  -o $(TARGET)$(EEXT) $(LIBS)

functions$(OEXT): functions.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c functions.c

plot$(OEXT): plot.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c plot.c

data$(OEXT): data.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c data.c

libfun$(SLEXT): functions$(OEXT) plot$(OEXT) data$(OEXT)
	$(AR) libfun.a $(LOBJ)

clean:
	$(RM) libfun$(SLEXT) $(LOBJ) testlibfun$(OEXT)

.PHONY: clean

