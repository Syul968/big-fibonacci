struct int128bit{
    unsigned long long left;
    unsigned long long right;
};
void setValues(struct int128bit *pts, unsigned long long left, unsigned long long right);
struct int128bit add(struct int128bit x, struct int128bit y);
void addBit(char **string, int *len, int carry);
char *toString(struct int128bit n);
