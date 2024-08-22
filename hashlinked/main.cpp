//George Paul Robert

#include <iostream>
#include <string>

struct MovieInfo {
    std::string director;
    std::string title;
    int year;
    float score;
    MovieInfo* next;

    MovieInfo() : year(0), score(0.0), next(nullptr) {}

    MovieInfo(const std::string& dir, const std::string& tit, int yr, float scr)
        : director(dir), title(tit), year(yr), score(scr), next(nullptr) {}
};

class HashTable {
private:

    static const int num_buckets = 10;


    MovieInfo* table[num_buckets];

    int hashFunction(const std::string& key) {
        return key.length() % num_buckets;
    }

public:
    HashTable() {
        for (int i = 0; i < num_buckets; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(const std::string& key, const MovieInfo& value) {
        int index = hashFunction(key);
        MovieInfo* newNode = new MovieInfo(value.director, value.title, value.year, value.score);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void remove(const std::string& key) {
        int index = hashFunction(key);
        MovieInfo* current = table[index];
        MovieInfo* prev = nullptr;

        while (current != nullptr) {
            if (current->title == key || current->director == key || current->year == std::stoi(key) || current->score == std::stof(key)) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

void update(const std::string& key, const MovieInfo& newValue) {
    int index = hashFunction(key);
    MovieInfo* current = table[index];

    while (current != nullptr) {
        if (current->title == key || current->director == key || current->year == std::stoi(key) || current->score == std::stof(key)) {
            current->director = newValue.director;
            current->title = newValue.title;
            current->year = newValue.year;
            current->score = newValue.score;
            return;
        }
        current = current->next;
    }
}


MovieInfo find(const std::string& key) {
    int index = hashFunction(key);
    MovieInfo* current = table[index];

    while (current != nullptr) {
        if ((current->title == key || current->director == key) ||
            (key == std::to_string(current->year) || key == std::to_string(current->score))) {
            return *current;
        }

        current = current->next;
    }

    return MovieInfo{};
}



    void enumerate() {
        for (int i = 0; i < num_buckets; ++i) {
            MovieInfo* current = table[i];
            while (current != nullptr) {
                std::cout << "Director: " << current->director << ", Title: " << current->title
                          << ", Year: " << current->year << ", Score: " << current->score << std::endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable movieTable;

    movieTable.insert("Rob Minkoff", {"Rob Minkoff", "The Lion King", 2019, 3.50});
    movieTable.insert("Bill Condon", {"Bill Condon", "Beauty and the Beast", 2017, 4.20});
    movieTable.insert("Josh Cooley", {"Josh Cooley", "Toy Story 4", 2019, 4.50});
    movieTable.insert("Brad Bird", {"Brad Bird", "Mission Impossible", 2018, 5.00});
    movieTable.insert("Lake Bell", {"Lake Bell", "The Secret Life of Pets", 2016, 3.90});

    std::cout << "Original Table:" << std::endl;
    movieTable.enumerate();

    movieTable.remove("The Secret Life of Pets");
    movieTable.remove("3.90");
    movieTable.remove("2016");
    movieTable.remove("Lake Bell");


    std::cout << "\nUpdated Table:" << std::endl;
    movieTable.enumerate();

    movieTable.update("Toy Story 4", {"Josh Cooley", "Toy Story 3", 2019, 4.50});
    movieTable.update("The Lion King", {"Rob Minkoff", "The Lion King", 2010, 4.20});
    movieTable.update("Toy Story 3", {"Lee Unkrich", "Toy Story 3", 2019, 4.50});
    movieTable.update("4.50", {"Lee Unkrich", "Toy Story 3", 2019, 5.00});



    std::cout << "\nUpdated Table:" << std::endl;
    movieTable.enumerate();


std::cout << "\nFinding records:" << std::endl;

MovieInfo missionImpossible = movieTable.find("Mission Impossible");
std::cout << "Mission Impossible: " << missionImpossible.title << ", Director: " << missionImpossible.director << ", Year: " << missionImpossible.year << ", Score: " << missionImpossible.score << std::endl;

MovieInfo billCondon = movieTable.find("Bill Condon");
std::cout << "Bill Condon: " << billCondon.director << ", Director: " << billCondon.title << ", Year: " << billCondon.year << ", Score: " << billCondon.score << std::endl;

MovieInfo released2018 = movieTable.find("2018");
std::cout << "Released in 2018: " << released2018.title << ", Director: " << released2018.director << ", Year: " << released2018.year << ", Score: " << released2018.score << std::endl;

MovieInfo score3_5 = movieTable.find("3.5");
std::cout << "Score 3.5: " << score3_5.title << ", Director: " << score3_5.director << ", Year: " << score3_5.year << ", Score: " << score3_5.score << std::endl;



    // std::cout << "Mission Impossible: " << missionImpossible.title << std::endl;
    // std::cout << "Bill Condon: " << billCondon.director << std::endl;
    // std::cout << "Released in 2018: " << released2018.title << std::endl;
    // std::cout << "Score 3.5: " << score3_5.score << std::endl;

    return 0;
}



