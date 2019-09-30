all: readwrite procon

readwrite: readwrite.c
	gcc readwrite.c -pthread -o readwrite

procon: procon.c
	gcc procon.c -pthread -o procon
	
clean:
	rm procon readwrite	
