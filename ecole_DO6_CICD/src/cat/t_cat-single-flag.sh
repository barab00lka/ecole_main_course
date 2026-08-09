#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
TEST_FILE="bytes.txt"

# Test each flag separately
for var in -b -e -n -s -t -v -E -T; do
    TEST1="$var $TEST_FILE"
    echo "$TEST1"
    ./my_cat $TEST1 > my_cat.txt
    cat $TEST1 > cat.txt
    DIFF_RES="$(diff -s my_cat.txt cat.txt)"
    if [ "$DIFF_RES" == "Files my_cat.txt and cat.txt are identical" ]; then
        (( COUNTER_SUCCESS++ ))
        echo "  SUCCESS"
    else
        echo "  FAIL"
        echo "$TEST1" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
    rm my_cat.txt cat.txt
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
