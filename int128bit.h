struct int128bit{
    unsigned long long left;
    unsigned long long right;
};
void setValues(struct int128bit *pts, unsigned long long left, unsigned long long right);
struct int128bit add(struct int128bit x, struct int128bit y);
void addBit(char **string, int *len, int carry);
char *toString(struct int128bit n);
struct int128bit and(struct int128bit a, struct int128bit b);
struct int128bit or(struct int128bit a, struct int128bit b);
struct int128bit xor(struct int128bit a, struct int128bit b);
struct int128bit ones(struct int128bit a);
struct int128bit twos(struct int128bit a);
struct int128bit leftShift(struct int128bit a, int n);