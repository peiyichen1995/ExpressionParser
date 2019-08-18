# ExpressionParser

This is an expression parser for simple math expressions.

It reads infix math expression from a text input file, converts each line into a post fix expression i.e. RPN. 

Each RPN is then forward evaluated into a single value.

## Sample input file

```
3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3

4 - 6 ^ 3 * 10 + ( 5 - 1 ^ 2 ) ^ 3

sin ( max ( 2 3 ) / 3 * 3.14159 )

max ( sin ( cos ( 3.14159 / 9 ) ) 8 ) - 8 ^ 5 + sin ( 8 ) ^ 5
min ( 8 1 ) + sin ( 8 ^ min ( 2 3 ) ) / 5 + max ( 8 1 )

sin ( factorial ( min ( 5 15 ) ) ) + 3
```

## Output

```
line 1: 
Tokens: 3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3 
= 3.00012
line 2: 
Tokens: 4 - 6 ^ 3 * 10 + ( 5 - 1 ^ 2 ) ^ 3 
= -2092
line 3: 
Tokens: sin ( max ( 2 3 ) / 3 * 3.14159 ) 
= 2.65359e-06
line 4: 
Tokens: max ( sin ( cos ( 3.14159 / 9 ) ) 8 ) - 8 ^ 5 + sin ( 8 ) ^ 5 
= -32759.1
line 5: 
Tokens: min ( 8 1 ) + sin ( 8 ^ min ( 2 3 ) ) / 5 + max ( 8 1 ) 
= 9.18401
line 6: 
Tokens: sin ( factorial ( min ( 5 15 ) ) ) + 3 
= 3.58061
```
