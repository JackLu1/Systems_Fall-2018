all: song_list.o music_library.o test.o song_list.h music_library.h
	gcc -o musicplayertest.out song_list.o music_library.o test.o 

run: all
	./musicplayertest.out

song_list.o: song_list.c
	gcc -c song_list.c

music_library.o: music_library.c music_library.h
	gcc -c music_library.c

test.o: test.c
	gcc -c test.c

clean:
	rm *.o
	rm musicplayertest.out

debug: debug_o debug_link

debug_o: song_list.c music_library.c test.c
	gcc -c song_list.c music_library.c test.c -g

debug_link: test.o song_list.o music_library.o song_list.h music_library.h
	gcc -o musicplayertest.out song_list.o music_library.o test.o -g

