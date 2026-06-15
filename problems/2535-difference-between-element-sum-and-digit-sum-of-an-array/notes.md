Let num be `abcdef`

`abcdef` = `abcde` \_ 10 + `f`  
10 \* `abcde` = 9 \* `abcde` + (`abcde`)

Now recurse for (`abcde`)..  
getting one digit off each step,  
until we get to single digit.

Remove single digits of each number in each step,  
essentially removing each digit of the number.

Add up the steps and we get:

9 \* (`abcde` + `abcd` + `abc` + `ab`)

This pattern is used to find the answer,  
without separately calculating element or digit sum.
