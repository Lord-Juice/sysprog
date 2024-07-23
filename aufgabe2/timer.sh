#!/bin/bash

# Function to calculate the average
average() {
    sum=0
    for time in "${times[@]}"; do
        sum=$(echo "$sum + $time" | bc)
    done
    avg=$(echo "scale=6; $sum / ${#times[@]}" | bc)
    echo $avg
}

# Arrays to store individual run times
times_bubblesort=()
times_java_bubblesort=()

# Run and time ./bubblesort 100000
echo "Timing ./bubblesort 100000"
for i in {1..10}; do
    start=$(date +%s.%N)
    ./bubblesort 100000 < /dev/null > /dev/null
    end=$(date +%s.%N)
    duration=$(echo "$end - $start" | bc)
    echo "Run $i: $duration seconds"
    times_bubblesort+=($duration)
done
avg_bubblesort=$(average "${times_bubblesort[@]}")
echo "Average time for ./bubblesort 100000: $avg_bubblesort seconds"

# Run and time java Bubblesort 100000
echo "Timing java Bubblesort 100000"
for i in {1..10}; do
    start=$(date +%s.%N)
    java Bubblesort 100000 < /dev/null > /dev/null
    end=$(date +%s.%N)
    duration=$(echo "$end - $start" | bc)
    echo "Run $i: $duration seconds"
    times_java_bubblesort+=($duration)
done
avg_java_bubblesort=$(average "${times_java_bubblesort[@]}")
echo "Average time for java Bubblesort 100000: $avg_java_bubblesort seconds"

# Determine which command was faster and by what margin
if (( $(echo "$avg_bubblesort < $avg_java_bubblesort" | bc -l) )); then
    margin=$(echo "$avg_java_bubblesort - $avg_bubblesort" | bc)
    echo "./bubblesort 100000 was faster by $margin seconds on average."
else
    margin=$(echo "$avg_bubblesort - $avg_java_bubblesort" | bc)
    echo "java Bubblesort 100000 was faster by $margin seconds on average."
fi
