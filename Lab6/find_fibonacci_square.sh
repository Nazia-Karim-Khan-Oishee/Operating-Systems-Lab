#!/bin/bash


is_perfect_square() {
local num="$1"
local sqrt_num=$(echo "sqrt($num)" | bc)
local int_sqrt_num=${sqrt_num%.*}
if [ "$((int_sqrt_num * int_sqrt_num))" -eq "$num" ]; then
return 0  
else
return 1  
fi
}

# Check if two parameters are provided
if [ "$#" -ne 2 ]; then
    echo "Syntax Error: Two parameters required (lower range and upper range)."
    echo "Usage: $0 <lower_range> <upper_range>"
    exit 1
fi

lower_range="$1"
upper_range="$2"

# Initialize variables for Fibonacci numbers
fibonacci_a=0
fibonacci_b=1


perfect_squares=""

echo "Fibonacci numbers in the range $lower_range to $upper_range:"
while [ "$fibonacci_a" -le "$upper_range" ]; do
    if [ "$fibonacci_a" -ge "$lower_range" ]; then
        echo -n "$fibonacci_a "
    fi
    fibonacci_c=$((fibonacci_a + fibonacci_b))
    fibonacci_a="$fibonacci_b"
    fibonacci_b="$fibonacci_c"
done
echo


echo "Perfect squares in the range $lower_range to $upper_range:"
for ((num = lower_range; num <= upper_range; num++)); do
    if is_perfect_square "$num"; then
        if [ -z "$perfect_squares" ]; then
            perfect_squares="$num"
        else
            perfect_squares="$perfect_squares $num"
        fi
    fi
done


echo "$perfect_squares"

