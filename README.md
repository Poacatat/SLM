SLM — Lab Project README
========================

Contents
--------
- src/        - source code and modules
- README      - this file
- example.txt - an example txt file for testing purposes


Installation
------------
1. Clone the repository:
    git clone <repository-url>
2. Enter the project directory:
    cd slm
3. Make the program:
    make
4. Run the binary:
    ./slm \<input_word_length\> example.txt \<total_output_length\>

Code
------------
Behavior:
- Builds an n-gram Markov model from the input file (contexts of $n$ words).
- Generates text by sampling next words from observed continuations until the specified word count is reached.
- Output is written to stdout.

### slm.cpp
The main file of the porgram, handles input and creates the generator object that is the bulk of the program. 



Contributing
------------
- Create issues for bugs or feature requests.
- Fork the repository, create a feature branch, and open a pull request.
- Keep commits small and focused. Include tests for new features or bug fixes.