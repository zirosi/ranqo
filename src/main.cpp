#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <list>

using namespace std;

list<string> quotesList;
set<string> quotes;
string version = "1.0.2 RELEASE";

int noQuotesCheck() {
  if (quotes.empty() == 1) {
    return 1;
  }
  if (quotes.size() == 0) {
    return 1;
  }
  return 0;
}

void helpPromt() {
  cout << "ranqo version: " << version << "\n";
  cout << "usage... ranqo <filepath> [argument]\n\n";
  cout << "arguments:\n";
  cout << "-s    ranqo <filepath> -p <number> : Shows a specific quote\n";
  cout << "-l    ranqo <filepath> -l : Lists all the quotes\n";
  cout << "-h    ranqo -h : Shows the help promt\n";
}

void loadQuotes(string filepath) {
  string singleQuote;

  ifstream QUOTEFILE(filepath);

  while(getline(QUOTEFILE, singleQuote)) {
    quotes.insert(singleQuote);
  }

  QUOTEFILE.close();
}

void loadQuotesList(string filepath) {
  string singleQuote;

  ifstream QUOTEFILE(filepath);

  while(getline(QUOTEFILE, singleQuote)) {
    quotesList.push_back(singleQuote);
  }

  QUOTEFILE.close();
}

void randomQuote() {
  srand(time(0));
  int selectedQuote = rand() % quotes.size();

  cout << *next(quotes.begin(), selectedQuote) << "\n";
}

void listQuotes() {
  for (string quote : quotes) {
    cout << quote << "\n";
  }
}

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
    if (argc == 2 && string(argv[1]) == "-h") {
      helpPromt();
      return 0;
    }

    loadQuotes(argv[1]);
    int noQuotes = noQuotesCheck();

    if (noQuotes == 1) {
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
    if (argc == 4 && string(argv[2]) == "-s") {
      loadQuotesList(argv[1]);

      int specifiedQuote = (atoi(argv[3]) - 1);

      cout << *next(quotesList.begin(), specifiedQuote) << "\n";
      return 0;
    }
  }
  return 1;
}
