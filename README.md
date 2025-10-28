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
The main file of the program, handles input and creates the generator object that administers the rest of the program. 

### Generator.cpp/h
Orchestrates model creation, training, and text generation. Parses CLI-like inputs (word length, input filename, desired output length) and produces a generated string to stdout.

### Model
Implements an n-gram character-level Markov model: maps context strings (length n) to frequency counts of following characters. Provides training from a file and sampling methods used by Generator.

When training the model it goes through the entire text, looking at a window $n$ characters large, moving along on chararacter at a time. For every word-next-letter pair it keep strack of how often it occurs using a map in a map. No normalisation of frequencies has to be done, see model.calculate_next_char(). 

From the observed frequencies the model choses a next letter, randomizing it off of previously seen word-next-letter pairs. Choosing based on observed distribution. If Model cannot sample a continuation for a context, for example when it creates a word that does not exist in the original text, it falls back to random_letter() (random start char).

Vim and certain other text editors always leave a trailing newline, this can lead to unintented newlines in the text generation. The program does not account for this in the slightest.


Contributing
------------
- Create issues for bugs or feature requests.
- Fork the repository, create a feature branch, and open a pull request.
- Keep commits small and focused. Include tests for new features or bug fixes.