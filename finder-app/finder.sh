if [ $# -eq 2 ]
then
    if [ -d $1 ]
    then
        NUMFILES=$(ls -1q $1 | wc -l)
        cd $1
        MATCH=$(grep $2 * | wc -l)
        echo "The number of files are $NUMFILES and the number of matching lines are $MATCH"
    else
        echo "First argument is not a directory"
        exit 1
    fi
else
    echo "Not all arguments provided"
    exit 1
fi