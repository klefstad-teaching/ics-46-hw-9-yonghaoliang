#include "ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "words.txt");

    string start, end;
    
    while (true) {
        cout << "\nEnter start word (or type '-1' to quit): ";
        cin >> start;
        if (start == "-1") break;

        cout << "Enter end word: ";
        cin >> end;

        vector<string> ladder = generate_word_ladder(start, end, word_list);
        print_word_ladder(ladder);
    }

    return 0;
}
