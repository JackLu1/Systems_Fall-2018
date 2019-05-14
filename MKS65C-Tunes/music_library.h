//music_library functions
void print_lib(struct song_node **);
void add_song(struct song_node **, char *, char *);
void clear_lib(struct song_node **);
int artist_exists(struct song_node **, char *);
void print_letter(struct song_node **, char);
void print_artist(struct song_node **, char *);
void delete_song(struct song_node **, char *, char *);
void shuffle(struct song_node **, int );
struct song_node ** create_lib();
struct song_node  * search_song(struct song_node **, char *, char *);
