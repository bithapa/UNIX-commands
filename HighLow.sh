#!/bin/bash

if [[ ! -e /HighLow.dat ]]; then
    touch HighLow.dat
fi
file="HighLow.dat"

echo "-----GAME HISTORY-----"
echo "\tGuesses\tGames"
while read line
do
    words=($line)
    echo "\t${words[0]}\t${words[1]}"
done < $file

echo "-----HIGH LOW GAME!-----"

SECRET=$1

if [[ ! $1 ]]
then
    echo "enter MAX_NUMBER:"
    read SECRET
fi

echo "Enter your guess:"
read guess
total_counter=1
total_games=1
total_guesses=0

while :
do
	if [[ $guess -gt $SECRET ]]; then
		echo "My number is less than $guess!"
	fi

	if [[ $guess -lt $SECRET ]]; then
		echo "My number is greater than $guess!"
	fi

	if [[ $guess == $SECRET ]]; then
        total_guesses=$(($total_guesses+$total_counter))
		echo "Great! That's my number! Your number of guesses for this game - $total_counter."
        echo "Would you like to play again?[Y/N]"
        read res
        if [[ $res == "N" ]]; then
            echo "Thanks for playing."
            echo "Total Guesses: $total_guesses, Total Games: $total_games"
            echo "$total_guesses $total_games" >> $file
            exit
        else
            ((total_games++))
            total_counter=0
            echo "enter MAX_NUMBER:"
            read SECRET
        fi
	fi
    echo "Enter your guess:"
    read guess
    ((total_counter++))
done
