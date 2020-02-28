#ifndef ALGRITHM_NOTES_SORT_H
#define ALGRITHM_NOTES_SORT_H

namespace sort {

    typedef struct {
        int *data;
        int len;
    } Data;

    void bubble(int [], int);

    void select(int [], int);

    void insert(int [], int);

    Data merge(Data);

    void quick(int *, int, int);
}

#endif //ALGRITHM_NOTES_SORT_H
