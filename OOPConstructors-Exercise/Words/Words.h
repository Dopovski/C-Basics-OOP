#pragma once
#include <string>
#include <map>

class Word {
private:
    std::string word;
    static std::map<std::string, size_t> wordCount;   // logical frequency
    static std::map<std::string, size_t> refCount;    // instance ref count

public:
    Word(const std::string& w) : word(w) {
        wordCount[word]++;
        refCount[word]++;
    }

    Word(const Word& other) : word(other.word) {
        // copy: track refs but don't double-count logical frequency
        refCount[word]++;
    }

    Word& operator=(const Word&) = delete;

    ~Word() {
        auto it = refCount.find(word);
        if (it != refCount.end()) {
            it->second--;
            if (it->second == 0) {
                refCount.erase(it);
                wordCount.erase(word);
            }
        }
    }

    const std::string& getWord() const { return word; }
    int getCount() const { return wordCount[word]; }

    bool operator<(const Word& other) const {
        return this->word < other.word;
    }
};
