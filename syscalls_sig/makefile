all: 
	@echo "using signals to interact with processes............"
	gcc -Wall signals.c  -o signals
	gcc -Wall sighup.c   -o sighup
	gcc -Wall sigtimer.c -o sigtimer
	@echo 
	@echo to use signals, follow the instructions in "signals_howto.txt"
	@echo to use sighup, follow the instructions in "sighup_howto.txt"
	@echo to use sigtimer just run:
	@echo $$ ./sigtimer

clean:
	rm -f *~ signals sighup sigtimer

