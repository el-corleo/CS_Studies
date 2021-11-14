#!/bin/sh

clear

# run rust compiler with given arguments
# display only full screen's worth of errors
# press enter for 1 line more
# press space for 1 screen more
# press q to quit
rustc $* --color always 2>&1 | more
