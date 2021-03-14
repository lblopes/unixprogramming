all: 
	@echo "examples: fork, wait, pipe, socket..............."
	gcc -Wall pipe.c   -o pipe
	gcc -Wall socket.c -o socket
	gcc -Wall server.c -o server
	gcc -Wall client.c -o client
	@echo 
	@echo use the commands as follows:
	@echo $$ ./pipe
	@echo Hello child \(...\)! I\'m your parent pid \(...\).
	@echo 
	@echo $$ ./socket quote.txt
	@echo Such is the nature of evil. 
	@echo Out there in the vast ignorance of the world it festers and spreads.
	@echo A shadow that grows in the dark.
	@echo A sleepless malice as black as the oncoming wall of night.
	@echo So it ever was.
	@echo So will it always be.
	@echo In time all foul things come forth.
	@echo -- Thranduil, Elven King
	@echo $$
	@echo # create two TABS or open 2 terminals
	@echo TAB1:
	@echo $$ ./server 
	@echo server listening at port 55901  # your port number will be different
	@echo TAB2:
	@echo $$ ./client 127.0.0.1 55901 quote.txt
	@echo TAB1: \(output\)
	@echo Such is the nature of evil. 
	@echo Out there in the vast ignorance of the world it festers and spreads.
	@echo A shadow that grows in the dark.
	@echo A sleepless malice as black as the oncoming wall of night.
	@echo So it ever was.
	@echo So will it always be.
	@echo In time all foul things come forth.
	@echo -- Thranduil, Elven King
	@echo $$ 

clean:
	rm -f *~ pipe socket server client

