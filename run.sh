#!/bin/sh
die () {
    echo >&2 "$@"
    exit 1
}

[ "$#" -ge 1 ] || die "at least 1 argument required, $# provided"

echo $1 | grep -- "-cpp$"
if [ $? -eq 0 ]; then
    ./run-cpp.sh "$@"
    exit 0
fi

echo $1 | grep -- "-rust$"
if [ $? -eq 0 ]; then
    ./run-rust.sh "$@"
    exit 0
fi

echo "Target name does not end with -cpp or -rust, no idea what to do"
exit 1