all: 
	@echo "examples: fork, wait, execl, execvp.................."
	gcc -Wall forkseq.c   -o forkseq
	gcc -Wall forkfor.c   -o forkfor
	gcc -Wall forkaddr.c  -o forkaddr
	gcc -Wall forkexecl.c -o forkexecl
	gcc -Wall shexecl.c   -o shexecl
	gcc -Wall shexecvp.c  -o shexecvp
	@echo 
	@echo use the commands as follows:
	@echo $$ ./forseq
	@echo $$ ./forfor
	@echo $$ ./forkaddr
	@echo $$ ./forkexecl "ls"    
	@echo $$ ./forkexecl "pwd"
	@echo $$ ./forkexecl "ls -l"  \#note error 
	@echo $$ ./shexecl
	@echo \> ls      \# your shell now!
	@echo \> pwd
	@echo \> ls -l   \# note error 
	@echo \> ps -A   \# note error 
	@echo \> quit
	@echo $$ ./shexecvp
	@echo \> ls      \# your shell now!
	@echo \> pwd
	@echo \> ls -l   \# works now
	@echo \> ps -A   \# works now
	@echo \> quit
	@echo $$         \# back to terminal shell

clean:
	rm -f *~ forkseq forkfor forkaddr forkexecl shexecl shexecvp

