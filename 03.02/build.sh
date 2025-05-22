#!/bin/bash
gcc $1 -Wall -Wextra -fsanitize=address,undefined -Og