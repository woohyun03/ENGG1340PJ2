#ifndef MAL_H
#define MAL_H

struct Mal {
    int row;
    int column;
    int previousRow;
    int previousColumn;
    bool can_finish;
    bool finished;
    bool carried;
};

#endif
