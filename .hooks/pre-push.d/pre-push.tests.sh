#!/bin/bash

check_gemshome() {
   if [ -z "$GEMSHOME" ]; then
      echo ""
      echo "Your GEMSHOME environment variable is not set! It should be set to"
      echo "$1"
      exit 1
   elif [ ! -d $GEMSHOME ]; then
      echo ""
      echo "Your GEMSHOME environment variable is set to $GEMSHOME -- this does"
      echo "not appear to be a directory. It should be set to"
      echo "$1"
      exit 1
   elif [ ! "$GEMSHOME" = "$1" -a ! "$GEMSHOME" = "${1}/" ]; then
      #try checking the inode incase there is a problem with symlinks
       if [ `stat -c "%i" $GEMSHOME` != `stat -c "%i" ${1}` ]; then
           echo ""
           echo "ERROR: GEMSHOME is expected to be $1 but it is currently"
           echo "$GEMSHOME    This will cause problems!"
           exit 1
       fi
   fi
}

cd ../
gemshome=`pwd`
cd -
check_gemshome $gemshome 

#Compile gmml if not compiled:
echo "Compiling gmml if necessary with ./make.sh NoClean no-wrap"
cd $GEMSHOME/
 ./make.sh no_clean no_wrap
cd -

echo "Running mandatory tests..."
cd $GEMSHOME/gmml/tests/
 bash compile_run_tests.bash
 result=$? # record the exit status from compile_run_tests.bash
cd -
if [ $result -eq 0 ] ; then
    echo  "All tests have passed. Pushing is allowed."
    exit 0
else
    echo "
         *****************************************************************
         The tests have failed! 
         Push cancelled.
         *****************************************************************
         "
    exit 1
fi
