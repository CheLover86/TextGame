all: lilcave src.zip

C = expand.c onoff.c inventory2.c match.c openclose.c reach.c toggle.c object.c misc.c location.c move.c inventory.c parsexec.c noun.c main.c
H = expand.h onoff.h inventory2.h match.h openclose.h reach.h toggle.h object.h misc.h location.h move.h inventory.h parsexec.h noun.h

lilcave: $(C) $(H)
	gcc -Wall -Wextra -Wpedantic -Werror $(C) -o $@

object.h: object.awk object.txt
	awk -v pass=h -f object.awk object.txt > $@

object.c: object.awk object.txt
	awk -v pass=c1 -f object.awk object.txt > $@
	awk -v pass=c2 -f object.awk object.txt >> $@

src.zip: $(C) $(H) object.txt Makefile
	zip -rq $@ $^

clean:
	$(RM) object.c object.h lilcave transcript.txt src.zip
