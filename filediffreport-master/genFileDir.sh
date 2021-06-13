#!/bin/bash


POEM="The Catcher in the Rye is set around the 1950s and is narrated by a young man named Holden Caulfield. Holden is not specific about his location while he’s telling the story, but he makes it clear that he is undergoing treatment in a mental hospital or sanatorium. The events he narrates take place in the few days between the end of the fall school term and Christmas, when Holden is sixteen years old.

Holden’s story begins on the Saturday following the end of classes at the Pencey prep school in Agerstown, Pennsylvania. Pencey is Holden’s fourth school; he has already failed out of three others. At Pencey, he has failed four out of five of his classes and has received notice that he is being expelled, but he is not scheduled to return home to Manhattan until Wednesday. He visits his elderly history teacher, Spencer, to say goodbye, but when Spencer tries to reprimand him for his poor academic performance, Holden becomes annoyed."



SAFE_TYT_STRINGS="WW91IE hhdmYgR m91bmQgQ WxsIFNhZ mUgdHl0 UEZpb GVzCg=="


SAFE_WQR_STRINGS="eU9VIG hBVkUgZ k9VTkQgY UxMIHNBR kUgV1FS IGZJT EVTCg=="


SAFE_RTL_STRINGS="eU91IG hBdkUg k91TmQgQ WxMIFNhR mUgUnRM UEZpT GVzCg=="



mkdir test

cd test



for WORD in $POEM; do

    NEW_EXT=`cat /dev/urandom | tr -cd 'a-f0-9' | head -c 1`

    FILENAME=`cat /dev/urandom | tr -cd 'a-f0-9' | head -c 5`

    echo "$WORD" >> "${FILENAME}.t${NEW_EXT}t"

done



for SAFE in $SAFE_TYT_STRINGS; do

    FILENAME=`cat /dev/urandom | tr -cd 'a-f0-9' | head -c 5`

    PERMS=`cat /dev/urandom | tr -cd '0-7' | head -c 3`

    echo "$SAFE" >> "${FILENAME}.tyt"

    chmod "$PERMS" "${FILENAME}.tyt"

    echo "${FILENAME}.tyt" >> ../.safe_filenames

done




for SAFE in $SAFE_WQR_STRINGS; do

    FILENAME=`cat /dev/urandom | tr -cd 'a-f0-9' | head -c 5`

    PERMS=`cat /dev/urandom | tr -cd '0-7' | head -c 3`

    echo "$SAFE" >> "${FILENAME}.wqr"

    chmod "$PERMS" "${FILENAME}.wqr"

    echo "${FILENAME}.wqr" >> ../.safe_filenames

done




for SAFE in $SAFE_RTL_STRINGS; do

    FILENAME=`cat /dev/urandom | tr -cd 'a-f0-9' | head -c 5`

    PERMS=`cat /dev/urandom | tr -cd '0-7' | head -c 3`

    echo "$SAFE" >> "${FILENAME}.rtl"

    chmod "$PERMS" "${FILENAME}.rtl"

    echo "${FILENAME}.rtl" >> ../.safe_filenames

done

cd ..
