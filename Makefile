TARGET = countdown percent

all:$(TARGET)

countdown:countdown.c
	gcc -Wall -o $@ $<

percent:percent.c
	gcc -Wall -o $@ $<

clean:
	rm -rf $(TARGET)

