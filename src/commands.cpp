#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <list>

#include "ranqo.hpp"

using namespace std;

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
  cout << "arguments:\n\n";
  cout << "-- Basic Arguments --\n";
  cout << "-h    ranqo -h : Shows the help promt\n";
  cout << "-l    ranqo <filepath> -l : Lists all the quotes\n";
  cout << "-s    ranqo <filepath> -s <number> : Shows a specific quote\n";
  cout << "-f    ranqo <filepath> -f <quote> : Finds a quote in the quotefile\n";
  cout << "-amt  ranqo <filepath> -amt : Lists the amount of quotes in a quotefile\n\n";
  cout << "-- Quote Manipulation --\n";
  cout << "-a    ranqo <filepath> -a \"quote\" : Adds a quote to the quotefile\n";
  cout << "-r    ranqo <filepath> -r \"quote\" : Removes a quote from the quotefile\n";
  cout << "-al   ranqo <filepath> -al \"quote\" : Adds a quote to the quotefile and lists it\n";
  cout << "-rl   ranqo <filepath> -rl \"quote\" : Removes a quote from the quotefile and lists it\n";
}

string argv2Quote(char *argv[], int beginingArgv, int argvSize) {
  string quote;
  for (int i = beginingArgv; i < argvSize; i++) {
    quote += argv[i];
    if (i != (argvSize - 1)) {
      quote += " ";
    }
  }
  return quote;
}

bool warnRepeatQuote() {
  string response;
  
  cout << "The quote you want to add is already here, do you want to add it again?\n";
  cout << "If there are more than one already, you will recive this message again\n";
  while (true) {
    cout << "Y/N: ";
    cin >> response;

    if (response == "Y") {
      return 1;
    }
    if (response == "N") {
      return 0;
    } else {
      cout << "that is not an option\n";
    }
  }
  return 1;
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

void removeQuote(string deletingQuote, string filepath) {
  ifstream QUOTEFILE(filepath);
  ofstream temp;
  temp.open("temp.rqo");

  string currentLine;

  while(getline(QUOTEFILE, currentLine)) {
    if (currentLine != deletingQuote) {
      temp << currentLine << endl;
    }
  }

  QUOTEFILE.close();
  temp.close();
  rename("temp.rqo", filepath.c_str());
}

void QuoteAmount(void) {

  int QuoteAmount = quotes.size();

  cout << "there are " << QuoteAmount << " quotes in the quotefile\n";
}

void addQuote(string addingQuote, string filepath) {
  ifstream QUOTEFILE(filepath);
  ofstream temp;
  temp.open("temp.rqo");
  
  string currentLine;
  int repeatQuote = 1;
  int doRepeatQuote = 1;

  while(getline(QUOTEFILE, currentLine)) {
    if (doRepeatQuote == 1 && currentLine == addingQuote) {
      cout << "cannot add the same line twice\n";
      doRepeatQuote = 0;
    } else {
      temp << currentLine << endl;
    }
  }

  if (repeatQuote == 1) {
    temp << addingQuote << endl;
  }

  QUOTEFILE.close();
  temp.close();
  rename("temp.rqo", filepath.c_str());
}

int findQuote(string findingQuote, string filepath) {
  ifstream QUOTEFILE(filepath);

  string currentLine;
  int currentLineNumber = 0;

  while(getline(QUOTEFILE, currentLine)) {
    currentLineNumber += 1;
    if (currentLine == findingQuote) {
      cout << "Found quote \'" << findingQuote << "\' at line " << currentLineNumber << "\n";
      return 0;
    }
  }

  cout << "There was not quote matching: " << findingQuote << "\n";
  return 1;
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