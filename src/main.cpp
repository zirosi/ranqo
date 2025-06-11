#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <list>

using namespace std;

list<string> quotesList;
set<string> quotes;
string version = "1.1 RELEASE";

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
  cout << "-- Basic Commands --\n";
  cout << "-h    ranqo -h : Shows the help promt\n";
  cout << "-l    ranqo <filepath> -l : Lists all the quotes\n";
  cout << "-s    ranqo <filepath> -s <number> : Shows a specific quote\n\n";
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

    if (argc == 4 && string(argv[2]) == "-s") {
      loadQuotesList(argv[1]);

      int specifiedQuote = (atoi(argv[3]) - 1);

      cout << *next(quotesList.begin(), specifiedQuote) << "\n";
      return 0;
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
