#include <iostream>
#include <fstream>

#include "ranqo.hpp"
#include "commands.cpp"

using namespace std;

int main(int argc, char *argv[]) {

  //checks if there is no arguments
  if (argc == 1) {
    cout << "usage... ranqo <filepath> [arguments]\n";
    cout << "ranqo version: " << version << "\n";
    cout << "please input a .rqo or .txt file\n";
    return 0;
  }

  //checks for more than zero arguments
  if (argc >= 2) {

    // checks for help
    if (argc == 2 && string(argv[1]) == "-h") {
      helpPromt();
      return 0;
    } else if (argc == 3 && string(argv[2]) == "-h") {
      helpPromt();
      return 0;
    }

    loadQuotes(argv[1]);
    int noQuotes = noQuotesCheck();

    if (noQuotes == 1 && string(argv[2]) != "-a") {
      cout << "The quotefile cannot be empty\n";
      return 1;
    }

    if (argc == 2 && string(argv[1]) != "-h") {
      randomQuote();
      return 0;
    }

    if (argc == 3 && string(argv[2]) == "-l") {
      listQuotes();
      return 0;
    }

    if (argc == 3 && string(argv[2]) == "-amt") {
      loadQuotes(argv[1]);
      QuoteAmount();
      return 0;
    }

    if (argc == 4 && string(argv[2]) == "-s") {
      loadQuotesList(argv[1]);

      int specifiedQuote = (atoi(argv[3]) - 1);

      cout << *next(quotesList.begin(), specifiedQuote) << "\n";
      return 0;
    }

    if (argc == 4 && string(argv[2]) == "-f") {
      loadQuotes(argv[1]);

      string specifiedQuote = argv[3];

      int foundQuote = findQuote(specifiedQuote, argv[1]);
      return foundQuote;
    }

    // quote management
    if (argc >= 4 && string(argv[2]) == "-a") {
      string addingQuote = argv2Quote(argv, 3, argc);
      addQuote(addingQuote, argv[1]);
      return 0;
    }

    if (argc >= 4 && string(argv[2]) == "-al") {
      string addingQuote = argv2Quote(argv, 3, argc);
      addQuote(addingQuote, argv[1]);
      listQuotes();
      return 0;
    }

    if (argc >= 4 && string(argv[2]) == "-r") {
      string removingQuote = argv2Quote(argv, 3, argc);
      removeQuote(removingQuote, argv[1]);
      return 0;
    }

    if (argc >= 4 && string(argv[2]) == "-rl") {
      string removingQuote = argv2Quote(argv, 3, argc);
      removeQuote(removingQuote, argv[1]);
      loadQuotes(argv[1]);
      listQuotes();
      return 0;
    }

    cout << "incorrect argument\n";
    return 1;
  }
}
