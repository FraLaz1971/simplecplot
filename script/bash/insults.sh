#!/usr/bin/env bash
echo "this bash program make insults to people who deserve"
date
echo "what is his name?"
read man
echo "what is her name?"
read woman
if  [[ "$man" == "Alessandro" ]] && [[ "$woman" == "Anna" ]]
then
    printf "Fuck you %s and %s! Pieces of shit!\n" "$man" "$woman"
else
    printf "Hey, glad to meet you. %s and %s!\n" "$man" "$woman"
fi
echo "bye"
date
