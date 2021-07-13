#include <stdio.h>     /* puts(), fopen(), fclose(), FILE, FILENAME_MAX */
#include <stdlib.h>    /* malloc(), realloc(), free() */
#include <string.h>    /* strcmp(), strlen(), strcpy(), strrchr() */
#include <sys/stat.h>  /* lstat(), struct stat */
#include <dirent.h>    /* DIR*, struct dirent, opendir(), readdir() */
#include <err.h>       /* warn() */
#include <errno.h>     /* errno */
#include "solution.h"

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
    ARRAY *messages;

    /* set up program */
    initArray(tyt_files, 5);
    initArray(wqr_files, 5);
    initArray(rtl_files, 5);
    initArray(invalid_files, 5);

    /* seperate files by extention */
    verify_files(tyt_files, wqr_files, rtl_files, invalid_files, dname);

    // read_files(tyt_files, wqr_files, rtl_files, invalid_files, valid_report, invalid_report);

    /* write valid report */
    fputs("[*] List of valid filenames\n", valid_report);
    write_report(valid_report, tyt_files, messages);
    write_report(valid_report, wqr_files, messages);
    write_report(valid_report, rtl_files, messages);
    fputs("[*] Encoded message\n", invalid_report);
    write_message(valid_report, messages);

    /* write invalid report */
    fputs("[*] List of invalid filenames\n", invalid_report);
    clearArray(messages);
    write_report(invalid_report, invalid_files, messages);
    fputs("[*] Message from files\n", invalid_report);
    write_message(invalid_report, messages);

    /* clean up resources */
    fclose(valid_report);
    fclose(invalid_report);
    freeArray(tyt_files);
    freeArray(wqr_files);
    freeArray(rtl_files);
    freeArray(invalid_files);

    return 0;
}

int verify_files(ARRAY *tyt_files, ARRAY *wqr_files, ARRAY *rtl_files, ARRAY *invalid_files, char *dname) {
    DIR *dir; /* pointer to directory */
    struct dirent *entry; /* single directory entry */
    char fn[FILENAME_MAX]; /* path name string */
    int len = strlen(dname);
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

        /* get filename of current entry into fn */
        strncpy(fn + len, entry->d_name, FILENAME_MAX - len);

        ext = strrchr(fn, '.');
        if(strcmp(ext,".tyt"))
            appendArray(tyt_files, fn);
        else if(strcmp(ext,".wqr"))
            appendArray(wqr_files, fn);
        else if(strcmp(ext,".rtl"))
            appendArray(rtl_files, fn);
        else /* invalid file extensions */
            appendArray(invalid_files, fn);
    }

    if(dir)
        closedir(dir);  /* close directory stream if open */
    return errno ? errno : WALK_OK;
}

void write_report(FILE *outfile, ARRAY *fn_list, ARRAY *messages) {
    char fn[FILENAME_MAX];  /* path name string */
    FILE *fp;  /* each file from fn_list */
    char *message;  /* one message per file */

    while(strcpy(fn, next(fn_list))) {
        fprintf(outfile, "[+] %s\n", fn);
        fp = fopen(fn, "r");
        appendArray(messages, read_file(&message, fp));
        fclose(fp);
    }
}

void write_messages(FILE *outfile, ARRAY *messages) {
    char *message;

    fprintf(outfile, "[-]");
    for(message = next(messages); message; message = next(messages)) {
        fprintf(outfile, " %s", message);
    }
    fprintf(outfile, "\n");
}

void initArray(ARRAY *arr, size_t initialSize) {
    arr->array = check_mem(malloc(initialSize * sizeof(char *)));
    arr->used = 0;
    arr->size = initialSize;
    arr->current = 0;
}

void appendArray(ARRAY *arr, char *element) {
    // arr->used is the number of used entries, because arr->array[arr->used++] updates arr->used only *after* the array has been accessed.
    // Therefore arr->used can go up to arr->size 
    if(arr->used == arr->size) {
        arr->size *= 2;
        arr->array = check_mem(realloc(arr->array, arr->size * sizeof(char *)));
    }
    arr->array[arr->used++] = element;
}

char *next(ARRAY *arr) {
    // check if at the end of array
    if(arr->current == arr->used)
        return NULL;
    else
        return arr->array[arr->current++];
}

void clearArray(ARRAY *arr) {
    size_t initialSize = 10;

    free(arr->array);
    arr->array = check_mem(malloc(initialSize * sizeof(char *)));
    arr->used = 0;
    arr->size = initialSize;
    arr->current = 0;
}

void freeArray(ARRAY *arr) {
    free(arr->array);
    arr->array = NULL;
    arr->used = arr->current = arr->size = 0;
}

char *read_file(char **str, FILE *stream) {
    char c;
    size_t n_char = 0;
    size_t size = 10;
    char *buffer = check_mem(malloc(sizeof(char) * size));

    while((c = getc(stream)) != EOF) {
        if(n_char >= size - 1) {
            buffer = check_mem(realloc(buffer, size *= 2));
        }
        buffer[n_char++] = c;
    }
    buffer = realloc(buffer, n_char + 1);
    buffer[n_char++] = '\0';
    return *str = buffer;
}

void *check_mem(void *ptr) {
    if(ptr == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    return ptr;
}