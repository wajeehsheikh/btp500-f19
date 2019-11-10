#!/bin/bash

SIZE=31250
ROUNDS=5

if [[ $1 ]]
then
    SIZE=$1
fi
echo "The array size is $SIZE"

if command -v g++ >/dev/null 2>&1
then
    g++ lab6.cpp generatedata.cpp timer.cpp lab6main.cpp -O3
fi

if [[ ! -f "a.out" ]]; then
    echo "a.out doesn't exist" >&2
    exit 1
fi


names=(Last Middle MedianOf3 Random)

# header
echo ",random,sorted,reversed,organpipe,rotated" > test.csv

echo "Generating data..."

for i in $(seq 1 $ROUNDS)
do
    for num in {0..3}
    do
        for line in "$(./a.out $SIZE $((num + 1)))"
        do
            n="${names[num]}_$i,$(echo "$line" | cut -d: -f2 | tr '\n' ',')"
            array=("${n::-1}")
        done
        echo "${array[*]}" >> test.csv
    done
done

echo "Calculating averages..."

# header
echo ",random,,sorted,,reversed,,organpipe,,rotated" > averages.csv


# calculate the average
i=0
for i in {0..3}
do
    line="$(grep ${names[i]} test.csv)"
    averages=()
    for index in {2..6} 
    do
        sum="$(cut -d, -f $index <<< "$line" | tr '\n' '+' | sed 's/e/*10^/g')"
        averages+=($(bc -l <<< "(${sum::-1})/$ROUNDS"))
    done
    echo "${names[i]} ${averages[@]}" | tr ' ' ',' | 
    sed 's/,/&,/g' | sed 's/,//' >> averages.csv
done

echo "Average,=AVERAGE(B2:B5),,=AVERAGE(D2:D5),,=AVERAGE(F2:F5),,=AVERAGE(H2:H5),,=AVERAGE(J2:J5)" >> averages.csv

echo "test.csv and averages.csv are generated for you"
echo "use averages.csv file to generate graph"
