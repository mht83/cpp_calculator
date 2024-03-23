# C++ Calculator

This repository contains a C++ calculator application capable of performing basic arithmetic operations. The application is designed with simplicity and ease of use in mind, providing a command-line interface for quick calculations.

## Features

- Basic arithmetic operations: addition, subtraction, multiplication, division.
- Command-line interface for ease of use.
- Error handling for invalid inputs.

## Dependencies

To compile and run this calculator, you will need:

- A C++ compiler (GCC recommended)
- Standard C++ libraries

## How to Use

1. Clone the repository:
git clone https://github.com/mht83/cpp_calculator.git
2. Navigate to the repository directory:
cd cpp_calculator
g++ -o calculator main.cpp
4. Run the calculator:
./calculator
## Algorithm and Functions

The C++ calculator application uses a straightforward algorithm to process mathematical expressions:

1. **Tokenization**: The input expression is broken down into tokens, which are the smallest units that can be processed, such as numbers and operators.

2. **Operation Detection**: The algorithm iterates through the tokens to detect mathematical operators. It uses a `for` loop to go through each token and compares it with the list of known operators.

3. **Sub-expression Calculation**: When an operator is detected, the algorithm identifies the sub-expression that needs to be calculated. This sub-expression includes the operator and its operands.

4. **Calculation Execution**: A separate function, `calculator`, is called to perform the calculation of the sub-expression. The result is then converted to a string.

5. **Token Replacement**: The original tokens of the sub-expression are removed from the list of tokens, and the result of the calculation is inserted in their place.

6. **Result Formation**: This process is repeated until all operations are performed and the final result is formed.

The key functions used in this process are:

- `main`: The entry point of the application where the user's input is received.
- `calculator`: A function that takes a string representing a mathematical expression and returns the calculated result.
- `erase` and `insert`: Functions used to modify the list of tokens by removing the used tokens and inserting the result of the calculation.

This algorithm ensures that the calculations are performed in the correct order, adhering to the rules of arithmetic precedence.

## Author
Mohammadhassan Tohidi @mht83
