.PHONY: clean all

.PRECIOUS: *.o

all: main.nes

clean:
	@rm -fv main.s
	@rm -fv main.o
	@rm -fv main.nes
	@rm -fv crt0.o

crt0.o: crt0.s
	ca65 crt0.s

%.o: %.c
	cc65 -Oirs $< --add-source
	ca65 $*.s -g
	rm $*.s

%.nes: %.o crt0.o
	ld65 -o $@ -C nes.cfg  crt0.o $< nes.lib
	rm crt0.o