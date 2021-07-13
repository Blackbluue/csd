#include <stdio.h>     /* FILE */
#include <stddef.h>    /* size_t */

typedef struct {
    char **array;
    size_t used;
    size_t size;
    size_t current;
} ARRAY;

int read_files(ARRAY *tyt_files, ARRAY *wqr_files, ARRAY *rtl_files, ARRAY *invalid_files, FILE *valid_report, FILE *invalid_report);
int verify_files(ARRAY *tyt_files, ARRAY *wqr_files, ARRAY *rtl_files, ARRAY *invalid_files, char *dname);
void write_report(FILE *outfile, ARRAY *fn_list, ARRAY *messages);
void write_messages(FILE *outfile, ARRAY *messages);
void initArray(ARRAY *arr, size_t initialSize);
void appendArray(ARRAY *arr, char *element);
char *next(ARRAY *arr);
void clearArray(ARRAY *arr);
void freeArray(ARRAY *arr);
char *read_file(char **str, FILE *stream);
void *check_mem(void *ptr);