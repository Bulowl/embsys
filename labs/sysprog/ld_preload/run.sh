#! /bin/sh

SCRIPT=`readlink -f $0`
ROOT_DIR=`dirname $SCRIPT`
PATH_LIB=/home/philibert/Documents/ENSTA/embsys/labs/sysprog/ld_preload

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib
LD_PRELOAD=$PATH_LIB/libhook.so $ROOT_DIR/bin/gps
