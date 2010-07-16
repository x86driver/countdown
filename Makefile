TARGET = countdown

all:$(TARGET)

countdown:countdown.c
	gcc -Wall -o $@ $<

clean:
	rm -rf $(TARGET)

