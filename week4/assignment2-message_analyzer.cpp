//-------------------------------+-------------+------------+
// Week 4 - Coding Assignment #1 | Calvin Losh | 07-05-2025 |
//-------------------------------+-------------+------------+
// Criteria:
// [X] Count characters
// [X] Count words
// [X] Identify sentences based on punctuation
// [X] Average word length, accurate to one decimal place
// [X] Detect basic emoticons
// [X] Identify and list words longer than 5 characters
// [X] Capitalize first letter of each sentence

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// honestly i am surprised this works, even though i expected it too lol
void capitalize(string &inp) {
    string p{"."};
    string x{"!"};
    string q{"?"};

    int pos_p{0};
    int pos_x{0};
    int pos_q{0};

    if (!inp.empty()) {
        inp[0] = toupper(inp[0]);
        while ((pos_p = inp.find(p, pos_p)) != string::npos) {
            inp[pos_p + 2] = toupper(inp[pos_p +2]);
            pos_p += p.length();
        }
        while ((pos_x = inp.find(x, pos_x)) != string::npos) {
            inp[pos_x + 2] = toupper(inp[pos_x +2]);
            pos_x += x.length();
        }
        while ((pos_q = inp.find(q, pos_q)) != string::npos) {
            inp[pos_q + 2] = toupper(inp[pos_q +2]);
            pos_q += q.length();
        }
    }
}

// was two functions, only difference was the contents of the while loop so i combined them.
void count_char_and_word(string inp, string &five_more, int &char_c, int &word_c) {
    stringstream s(inp);
    string word{};

    while (s >> word) {
        char_c += word.length();
        word_c++;

        if (word.length() > 5 ) {
            five_more.append(word + ", ");
        }
    }
}

// my best approximation without developing an LLM lol, give me $20 and who knows, i might
void count_sentence(string inp, int &sentence_c) {
    string p{"."};
    string x{"!"};
    string q{"?"};

    int pos_p{0};
    int pos_x{0};
    int pos_q{0};

    while ((pos_p = inp.find(p, pos_p)) != string::npos) {
        sentence_c++;
        pos_p += p.length();
    }
    while ((pos_x = inp.find(x, pos_x)) != string::npos) {
        sentence_c++;
        pos_x += x.length();
    }
    while ((pos_q = inp.find(q, pos_q)) != string::npos) {
        sentence_c++;
        pos_q += q.length();
    }
}

void word_len_avg(double &avg_count, int char_c, int word_c) {
    avg_count = char_c / word_c;
}

void emote(string inp, bool &emot) {
    if (inp.find(":)") != string::npos) {
        emot = true;
    } else if (inp.find(":D") != string::npos) {
        emot = true;
    } else if (inp.find(":(") != string::npos) {
        emot = true;
    } else if (inp.find(":P") != string::npos) {
        emot = true;
    }
}

int main() {
    string usr_input{};
    string usr_input_cap{};
    string five_plus_words{};

    bool emoticons{};

    int char_count{};
    int word_count{};
    int sentence_count{};
    double avg_word_len{};

    cout << "\nTEXT MESSAGE ANALYZER"
         << "\n---------------------"
         << "\nEnter your message\n> ";

    getline(cin, usr_input);
    count_char_and_word(usr_input, five_plus_words, char_count, word_count);
    count_sentence(usr_input, sentence_count);
    word_len_avg(avg_word_len, char_count, word_count);
    emote(usr_input, emoticons);
    capitalize(usr_input);

    cout << "\nWord Count: " << word_count
         << "\nCharacter Count: " << char_count
         << "\nSentence Count: " << sentence_count
         << "\nAverage word length: " << avg_word_len
         << "\nEmoticons used?: " << boolalpha << emoticons
         << "\n\nWords with more than 5 characters: \n" << five_plus_words
         << "\ncapt: \n" << usr_input;

    return 0;
}