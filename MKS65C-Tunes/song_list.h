struct song_node {
    char name[100];
    char artist[100];
    struct song_node *next;
};

//song_list functions
void print_list(struct song_node *);
void print_song(struct song_node *);
struct song_node *add_node(struct song_node *, char *, char *);
struct song_node *add_node_sorted(struct song_node *, char *, char *);
struct song_node *free_list(struct song_node *);
struct song_node *find_node(struct song_node *, char *, char *);
struct song_node *find_node_artist(struct song_node *, char *);
struct song_node *remove_node(struct song_node *, struct song_node *);
struct song_node *random_node(struct song_node *);

