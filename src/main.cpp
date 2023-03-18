#include "utils.h"

bool isAlpha(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); 
}

char lower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

bool isOption(string opt) {
    set<string> opts = {"-n", "-w", "-c", "-r"};
    return (opts.count(opt) != 0);
}

bool isOptionWithValue(string opt) {
    set<string> opts = {"-h", "-t", "-j"};
    return (opts.count(opt) != 0);
}

bool isDuplicate(map<char, char>& opt2val, string& arg) {
    return (opt2val.count(arg.at(1)) == 1);
}

void lexerOption(queue<string>& args, map<char, char>& opt2val) {
    if (isDuplicate(opt2val, args.front())) {
        stringstream err;
        err << "duplicate option: ";
        err << args.front();
        throw logic_error(err.str());
    } else {
        opt2val[args.front().at(1)] = 0;
        args.pop();
    }
}

void lexerOptionWithValue(queue<string>& args, map<char, char>& opt2val) {
    string opt = args.front();
    args.pop();
    if (args.empty()) {
        stringstream err;
        err << "option that should have argument does not have argument: ";
        err << opt;
        throw logic_error(err.str());
    } else {
        if (args.front().size() == 1 && isAlpha(args.front().at(0))) {
            if (isDuplicate(opt2val, opt)) {
                stringstream err;
                err << "duplicate option: ";
                err << opt;
                throw logic_error(err.str());
            } else {
                opt2val[opt.at(1)] = args.front().at(0);
                args.pop();
            }
        } else {
            stringstream err;
            err << "option has illegal argument: ";
            err << opt;
            err << " has ";
            err << args.front();
            throw logic_error(err.str());
        } 
    }
}

void lexerFileName(queue<string>& args, string& fileName) {
    if (args.front().at(0) == '-') {
            stringstream err;
            err << "illegal option: ";
            err << args.front();
            throw logic_error(err.str());
    }
    if (fileName.size() == 0) {
        fileName = args.front();
        args.pop();
    } else {
        stringstream err;
        err << "duplicate fileName: ";
        err << args.front();
        throw logic_error(err.str());
    }
}

void lexerArgs(int argc, char* argv[], map<char, char>& opt2val, string& fileName) {
    queue<string> args; 
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        args.push(arg);
    }

    while (!args.empty()) {
        if (isOption(args.front())) {
            lexerOption(args, opt2val);
        } else if (isOptionWithValue(args.front())) {
            lexerOptionWithValue(args, opt2val);
        } else {
            lexerFileName(args, fileName);
        }
    } 
}

void isLegalOpt(map<char, char>& opt2val) {
    if (opt2val.count('n') + opt2val.count('w') + opt2val.count('c') < 1) {
        stringstream err;
        err << "missing functional parameters (-n -w -c)";
        throw logic_error(err.str());
    } else if (opt2val.count('n') + opt2val.count('w') + opt2val.count('c') > 1) {
        stringstream err;
        err << "functional parameters are not compatible";
        throw logic_error(err.str());
    }
}

int readWords(string fileName, char** words) {
    ifstream readFile(fileName);

    if (readFile.fail()) {
        stringstream err;
        err << "file does not exist";
        throw logic_error(err.str());
    }

    string data;
    int cnt = 0;
    vector<char> wordBuf;

    while (getline(readFile, data)) {
        data += "\n";
        for (int i = 0; i < data.size(); i++) {
            if (isAlpha(data.at(i))) {
                wordBuf.push_back(lower(data.at(i)));
            } else {
                if (wordBuf.size() > 0) {
                    wordBuf.push_back('\0');
                    words[cnt] = (char *) malloc(sizeof(char) * wordBuf.size());
                    for (int j = 0; j < wordBuf.size(); j++) {
                        words[cnt][j] = wordBuf[j];
                    }
                    wordBuf.clear();
                    cnt++;
                }
            }
        }
    }

    return cnt;
}


int main(int argc, char* argv[]) {
    map<char, char> opt2val;
    string fileName;

    try {
        lexerArgs(argc, argv, opt2val, fileName);
        isLegalOpt(opt2val); 
    
        char **words = (char **) malloc(sizeof(char *) * MAX_WORDS_NUM);
        char **result = (char**) malloc (sizeof (char*) * MAX_CHAINS_NUM);
        int length = readWords(fileName, words);
        if (length == 0) {
            throw logic_error("the file content is empty");
        }

        char head = (opt2val.count('h') > 0) ? opt2val['h'] : '\0';
        char tail = (opt2val.count('t') > 0) ? opt2val['t'] : '\0';
        char ban = (opt2val.count('j') > 0) ? opt2val['j'] : '\0'; 
        bool allow_circle = (opt2val.count('r'));

        if (head == ban && ban != '\0') {
            throw logic_error("-h and -j cannot have the same value");
        }

        int ret;

        ofstream outFile("solution.txt", ios::trunc);
        string ans;

        if (opt2val.count('n') > 0) {
            if (opt2val.count('h') + opt2val.count('t') + opt2val.count('j') + opt2val.count('r') 
            + opt2val.count('w') + opt2val.count('c') > 0) {
                throw logic_error("-n can only be used alone");
            }
            ret = countChains(words, length, result);
            if (ret == 0) {
                throw logic_error("there is no matching result");
            }
            cout << ret << endl;
            ans += to_string(ret) + '\n';
        } else if (opt2val.count('w') > 0) {
            ret = getLongestWordChain(words, length, result, head, tail, ban, allow_circle);
            if (ret <= 1) {
                throw logic_error("there is no matching result");
            }
        } else if (opt2val.count('c') > 0) {
            ret = getLongestCharChain(words, length, result, head, tail, ban, allow_circle);
            if (ret <= 1) {
                throw logic_error("there is no matching result");
            }
        }

        if (ret > 20000) {
            throw logic_error("the result is too long");
        }

        for (int i = 0; i < ret; i++) {
            string s = result[i];
            cout << s << endl;
            ans += s + '\n';
        }

        outFile << ans;

    } catch (exception& e) {
        string err = e.what();
        cerr << "error: " + err << endl; 
    }

    return 0;
}