#!/bin/sh

PROJECT=OS2Web
VERSION=$1
DATE=`date "+%s"`

MSG=";Added by OS2Web `date "+%Y-%m-%d"`\nproject=$PROJECT\nversion=$VERSION\ntimestamp=$DATE\n"

echo $MSG

if [ -z "$VERSION" ]; then
  echo "Please specify version number ie. 1.3"
else
  for f in `find . -name *.info`; do
    echo $MSG >> $f;
  done
fi
