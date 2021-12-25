assembler: assembler.o firstPass.o lineUtil.o macroLinkList.o preAssembler.o
	gcc -Wall -ansi -pedantic -o assembler assembler.o firstPass.o lineUtil.o macroLinkList.o preAssembler.o
assembler.o: assembler.c assembler.h 
	gcc -g -Wall -ansi -pedantic -o assembler.o -c assembler.c 
firstPass.o: firstPass.c firstPass.h 
	gcc -g -Wall -ansi -pedantic -o firstPass.o -c firstPass.c 
preAssembler.o: preAssembler.c preAssembler.h 
	gcc -g -Wall -ansi -pedantic -o preAssembler.o -c preAssembler.c 
lineUtil.o: lineUtil.c lineUtil.h assemblerDefine.h
	gcc -g -Wall -ansi -pedantic -o lineUtil.o -c lineUtil.c 
macroLinkList.o: macroLinkList.c macroLinkList.h assemblerDefine.h
	gcc -g -Wall -ansi -pedantic -o macroLinkList.o -c macroLinkList.c 

clean:
	rm -f *.o assembler
