In programming languages like C, C++, Java...

Modulus operator performs truncated division. So,

```cpp
int x = -7;
int y = 5;

std::cout << x % y << std::endl;
```

The underlying formula being: `a - b * (int)(a / b)`

Will give output as `-2`. To get the actual answer we would do `(a % b + b) % b`.

Whereas in python,

```py
x: int = -7
y: int = 5

print(x % y)
```

Will output `3` (which is mathematically correct). This is by using floored division.

The underlying formula being: `a - b * floor(a / b)`

Hence, when writing the program in the former languages (i.e. not Python), we dont need to worry about the number's sign, as `digit` will always get the digit at face value with the sign.
