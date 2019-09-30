all: readwrite procon dinphil

readwrite: readwrite.c
	gcc readwrite.c -pthread -o readwrite

procon: procon.c
	gcc procon.c -pthread -o procon

dinphil: dinphil.c
	gcc dinphil.c -pthread -o dinphil

clean:
	rm procon readwrite dinphil
