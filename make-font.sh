#!/bin/bash

set -e

width=$1
height=$2
size=$3
fontfile=$4
outfile=$5
convert=$6
shift 5

if [ -z "$width" -o -z "$height" -o -z "$size" -o -z "$fontfile" -o -z "$outfile" ]; then
    echo "Usage: $0 <width> <height> <size> <fontfile> <outfile> [convert options]"
    exit 1
fi

(
for ord in $(seq 32 126); do
    printf "\\x$(printf %x $ord)\\n"
done
) | convert \
    -page ${width}x$((height*95)) \
    -background black \
    -fill white \
    -antialias \
    -font $fontfile \
    -density 72 \
    -gravity north \
    -pointsize $size \
    $* \
    -define quantum:format=unsigned \
    -depth 8 \
    label:\@- \
    -crop ${width}x$((height*95)) \
    gray:$outfile
