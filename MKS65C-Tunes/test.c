#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "song_list.h"
#include "music_library.h"

void test_song_list()
{
    printf("===Testing basic linked list operations===\n");

    printf(":::Empty list:::\n");
    struct song_node *song_list = 0;
    print_list(song_list);

    printf(":::Add songs:::\n");
    song_list = add_node(song_list, "Red Hot Chili Peppers", "Otherside");
    song_list = add_node(song_list, "Queen", "Bohemeian Rhapsody");
    song_list = add_node(song_list, "John Coltrane", "Blue Train");
    song_list = add_node(song_list, 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAb", 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAb");
    print_list(song_list);
    
    printf(":::Finding [John Coltrane - Blue Train]:::\n");
    print_song(find_node(song_list, "John Coltrane", "Blue Train"));

    printf(":::Finding [JynX - Present World Overhaul]:::\n");
    printf("%p\n", find_node(song_list, "JynX", "Present World Overhaul"));

    printf(":::Finding a song by Queen:::\n");
    print_song(find_node_artist(song_list, "Queen"));

    printf(":::Finding a song by Logan Paul:::\n");
    printf("%p\n", find_node_artist(song_list, "Logan Paul"));

    printf(":::Remove a node:::\n");
    song_list = remove_node(song_list, 
            find_node(song_list, "Red Hot Chili Peppers", "Otherside"));
    print_list(song_list);

    printf(":::Remove head:::\n");
    song_list = remove_node(song_list, song_list);
    print_list(song_list);

    printf(":::Remove everything:::\n");
    song_list = remove_node(song_list, song_list);
    song_list = remove_node(song_list, song_list);
    print_list(song_list);

    printf("===Testing add_node_sorted()===\n");
    song_list = add_node_sorted(song_list, "Paul McCartney", "Temporary Secretary");
    song_list = add_node_sorted(song_list, "Beatles", "Let it Be");    
    song_list = add_node_sorted(song_list, "ABBA", "Dancing Queen");    
    song_list = add_node_sorted(song_list, "Queen", "Killer Queen");
    song_list = add_node_sorted(song_list, "Vanilla Ice", "Ice Ice Baby");
    song_list = add_node_sorted(song_list, "Queen", "We Will Rock You");
    song_list = add_node_sorted(song_list, "Queen", "Don't Stop Me Now");
    song_list = add_node_sorted(song_list, "ABBA", "Chiquita");
    song_list = add_node_sorted(song_list, "Vanilla Ice", "Play That Funky Music");
    print_list(song_list);

    printf(":::Printing random songs:::\n");
    print_song(random_node(song_list));
    print_song(random_node(song_list));
    print_song(random_node(song_list));
    print_song(random_node(song_list));
    print_song(random_node(song_list));

    print_song(find_node(song_list, "Beatles", "Let it Be"));
    song_list = remove_node(song_list, find_node(song_list, "Beatles", "Let it Be"));
    printf("\n\n\n\n\n");
    print_list(song_list);

    free_list(song_list);
}

void test_lib(){
   struct song_node **lib = create_lib();
   printf(":::Printing empty library:::\n");
   print_lib(lib);
   printf(":::Adding songs:::\n");
   add_song(lib, "Weird Al Yankovic", "Amish Paradise");
   add_song(lib, "Drake", "Hotline Bling");
   add_song(lib, "Earth, Wind & Fire", "September");
   add_song(lib, "6ix9ine", "a");
   add_song(lib, "drake", "Wii Shop Bling");
   add_song(lib, "drake", "Wii Shop Bling 5");
   add_song(lib, "drake", "Wii Shop Bling 3");
   add_song(lib, "dragon", "test song");
   add_song(lib, "Eagles", "Hotel California");
   print_lib(lib);
   printf(":::Searching for [Eagles - Hotel California]:::\n");
   print_song(search_song(lib, "Eagles", "Hotel California"));
   printf(":::Searching for [Luis Fonsi - Despacito]:::\n");
   printf("%p\n", search_song(lib, "Luis Fonsi", "Despacito"));
   printf(":::Searching for [6ix9ine - a]:::\n");
   print_song(search_song(lib, "6ix9ine", "a"));
   print_song(find_node_artist(lib[3], "drake"));
    
   printf("artist_exists test\n");
   printf("%d\n", artist_exists(lib, "dont exist"));
   printf("%d\n", artist_exists(lib, "drake"));
   //clear_lib(lib);
   //printf(":::Printing cleared library:::\n");
   //print_lib(lib);
   printf("print_letter test\n");
   for (int i = 0; i < 28; i++){
       print_letter(lib, 'a' + i);
   }

   printf("print_artist test\n");
   print_artist(lib, "Drake");
   printf("check didnt break\n");
   print_letter(lib, 'd');

   printf("\n\ndelete_song test\n\n");
   delete_song(lib, "drake", "Wii Shop Bling 5");
   print_lib(lib);
   printf("\n\ndelete_song test\n\n");
   delete_song(lib, "drake", "fake song 5");
   print_lib(lib);

   printf("\n\nshuffle test\n\n");
   shuffle(lib, 5);
   //shuffle(lib, 0);
   //shuffle(lib, 14);
}

int main()
{
    srand(time(NULL));
    //test_song_list();
    test_lib();
    return 0;
}

