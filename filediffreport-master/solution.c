#include <stdio.h>     /* puts(), fopen(), fclose(), FILE, FILENAME_MAX */
#include <stdlib.h>    /* malloc(), free() */
#include <string.h>    /* strcmp(), strlen(), strcpy(), strrchr() */
#include <sys/stat.h>  /* lstat(), struct stat */
#include <dirent.h>    /* DIR*, struct dirent, opendir(), readdir() */
#include <errno.h>     /* errno */

typedef struct {
  char **array;
  size_t used;
  size_t size;
} ARRAY;

int walk_dir(ARRAY *tyt_files, ARRAY *wqr_files, ARRAY *rtl_files, ARRAY *invalid_files, FILE *valid_report, FILE *invalid_report);
void verify_files(ARRAY *tyt_files, ARRAY *wqr_files, ARRAY *rtl_files, ARRAY *invalid_files, char *dname);
void write_report(FILE *outfile, ARRAY *fn_list);
void initArray(ARRAY *arr, size_t initialSize);
void appendArray(ARRAY *arr, char *element);
void freeArray(ARRAY *arr);

/* error numbers */
enum {
    WALK_OK,
    WALK_BADIO
};

int main(void) {
    char *dname = "./";
    FILE *valid_report = fopen("valid_files.txt", "w");
    FILE *invalid_report = fopen("invalid_files.txt", "w");
    ARRAY *tyt_files;
    ARRAY *wqr_files;
    ARRAY *rtl_files;
    ARRAY *invalid_files;

    initArray(tyt_files, 5);
    initArray(wqr_files, 5);
    initArray(rtl_files, 5);
    initArray(invalid_files, 5);

    verify_files(tyt_files, wqr_files, rtl_files, invalid_files, dname);

    walk_dir(tyt_files, wqr_files, rtl_files, invalid_files, valid_report, invalid_report);

    fclose(valid_report);
    fclose(invalid_report);
    freeArray(tyt_files);
    freeArray(wqr_files);
    freeArray(rtl_files);
    freeArray(invalid_files);

    return 0;
}

/* function to walk a directory tree
    dname          -> directory name
    valid_report   -> report document for valid files
    invalid_report -> report document for invalid files */
int walk_dir(ARRAY *tyt_files, ARRAY *wqr_files, ARRAY *rtl_files, ARRAY *invalid_files, FILE *valid_report, FILE *invalid_report) {
    DIR *dir; /* pointer to directory */
    struct dirent *entry; /* single directory entry */
    struct stat st; /* file stat*/
    char fn[FILENAME_MAX]; /* path name string */
    int res = WALK_OK; /* default return code */
    int len = strlen(dname);
    int dname_len;

    /* set path name */
    strcpy(fn, dname);

    dir = opendir(dname);

    errno = 0;
    /* loop over directory for each entry */
    while((entry = readdir(dir))) {
        if(entry->d_name[0] == '.')
            continue; /* skip hidden files */
        if(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;  /* skip "." and ".." */

        /* get filename of current entry into fn */
        strncpy(fn + len, entry->d_name, FILENAME_MAX - len);
        dname_len = len + strlen(entry->d_name);
        lstat(fn, &st);
        
        if(S_ISLNK(st.st_mode))
            continue; /* don't follow symlink */
        /* print file name to report file if compatible */
        fprintf(valid_report, "%s\n", fn);
    }
    if(dir)
        closedir(dir);  /* close directory stream if open */
    return res ? res : errno ? WALK_BADIO : WALK_OK;
}

void verify_files(ARRAY *tyt_files, ARRAY *wqr_files, ARRAY *rtl_files, ARRAY *invalid_files, char *dname) {
    DIR *dir; /* pointer to directory */
    struct dirent *entry; /* single directory entry */
    struct stat st; /* file stat*/
    char fn[FILENAME_MAX]; /* path name string */
    int res = WALK_OK; /* default return code */
    int len = strlen(dname);
    int dname_len;
    char *ext; /* file extension */
    
    /* set path name */
    strcpy(fn, dname);

    dir = opendir(dname);

    errno = 0;
    while((entry = readdir(dir))) {
        if(entry->d_name[0] == '.')
            continue; /* skip hidden files */
        if(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;  /* skip "." and ".." */

        ext = strrchr(entry->d_name, '.');
        if(strcmp(ext,".tyt")) {

        } else if(strcmp(ext,".wqr")) {

        } else if(strcmp(ext,".rtl")) {
            
        } else { /* invalid file extensions */

        }
        /* get filename of current entry into fn */
        strncpy(fn + len, entry->d_name, FILENAME_MAX - len);
        dname_len = len + strlen(entry->d_name);
        lstat(fn, &st);
        
        if(S_ISLNK(st.st_mode))
            continue; /* don't follow symlink */
        /* print file name to report file if compatible */
        // fprintf(valid_report, "%s\n", fn);
    }
}

void write_report(FILE *outfile, ARRAY *fn_list) {

}

void initArray(ARRAY *arr, size_t initialSize) {
    arr->array = malloc(initialSize * sizeof(char *));
    arr->used = 0;
    arr->size = initialSize;
}

void appendArray(ARRAY *arr, char *element) {
    // arr->used is the number of used entries, because arr->array[arr->used++] updates arr->used only *after* the array has been accessed.
    // Therefore arr->used can go up to arr->size 
    if (arr->used == arr->size) {
        arr->size *= 2;
        arr->array = realloc(arr->array, arr->size * sizeof(char *));
    }
    arr->array[arr->used++] = element;
}

void freeArray(ARRAY *arr) {
    free(arr->array);
    arr->array = NULL;
    arr->used = arr->size = 0;
}