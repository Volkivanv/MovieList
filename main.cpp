#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <vector>

int main() {
/*
    nlohmann::json movie;
    movie["Pulp Fiction"] =
            {
            {"country", "USA"},
            {"date", 1994},
            {"studio", "A Band Apart"},
            {"scenario author", "Quentin Tarantino"},
            {"director", "Quentin Tarantino"},
            {"producer", "Lawrence Bender"},
            {"actors",
            { "Vincent Vega", "John Travolta" },
            { "Jules Winnfield", "Samuel L. Jackson" },
            { "Butch Coolidge", "Bruce Willis" },
            { "Mia Wallace", "Uma Thurman" }
            }
    };

    movie["Green Mile"] =
            {
                    {"country", "USA"},
                    {"date", 1999},
                    {"studio", "Castle Rock Entertainment"},
                    {"scenario author", "Stephen King"},
                    {"director", "Frank Darabont"},
                    {"producer", "Frank Darabont"},
                    {"actors",
                            { "Paul Edgecomb", "Tom Hank" },
                            { "Brutus Howell", "David Morse" },
                            { "Jan Edgecomb", "Bonnie Hunt" },
                            { "John Coffey", "Michael Clarke Duncan" }
                    }
            };
    movie["Ivan Vasilievich Changes Profession"] =
            {
                    {"country", "USSR"},
                    {"date", 1973},
                    {"studio", "Mosfilm"},
                    {"scenario author", "Vladlen Bakhnov"},
                    {"director", "Leonid Gaidai"},
                    {"producer", "Arkady Ashkinasy"},
                    {"actors",
                            { "Alexander Timofeev", "Alexander Demyanenko" },
                            { "Ivan Terrible", "Yury Yakovlev" },
                            { "George Miloslavsky", "Leonid Kuravlev" },
                            { "Uliyana Andreevna Bunsh", "Natalya Krachkovskaya" }
                    }
            };
    movie["Knockin' on Heaven Door"] =
            {
                    {"country", "Germany"},
                    {"date", 1997},
                    {"studio","Mr. Brown Entertainment"},
                    {"scenario author", "Thomas Jahn"},
                    {"director", "Thomas Jahn"},
                    {"producer", "Til Schweiger"},
                    {"actors",
                            { "Martin Brest", "Til Schweiger" },
                            { "Rudi Wurlitzer", "Jan Josef Liefers" },
                            { "Henk - der Belgier", "Thierry Van Werveke" },
                            { "Abdul - der Araber", "Moritz Bleibtreu" }
                    }
            };
    movie["The Shawshank Redemption"] =
            {
                    {"country", "USA"},
                    {"date", 1994},
                    {"studio","Castle Rock Entertainment"},
                    {"scenario author", "Frank Darabont"},
                    {"director", "Frank Darabont"},
                    {"producer", "Niki Marvin"},
                    {"actors",
                            { "Andy Dufresne", "Tim Robbins" },
                            { "Ellis Boyd «Red» Redding", "Morgan Freeman" },
                            { "Warden Norton", "Bob Gunton" },
                            { "Heywood", "William Sadler" }
                    }
            };

    std::ofstream file("movieInfo.json");
    if(file) {
        file << movie;
    } else {
        std::cerr<<"file is not opened";
    }
    file.close();
*/
    std::ifstream rFile("movieInfo.json");

    if(rFile) {

        nlohmann::json oMovie;
        rFile >> oMovie;
        std::string actorNames;
        std::cout << "Input name of actor" << std::endl;
        std::cin >> actorNames;

        /*for (auto it = oMovie.begin(); it != oMovie.end(); ++it) {
            std::cout << it.key() << " " << it.value() << std::endl;
        }
         */
        std::vector<std::string>films, roles;

        for (auto it = oMovie.begin(); it != oMovie.end(); ++it) {

            for(int i = 1; i < oMovie[it.key()][6].size(); i++){
                 std::string actor = oMovie[it.key()][6][i][1];
                 if(actor.find(actorNames) != -1){
                     films.push_back(it.key());
                     roles.push_back(oMovie[it.key()][6][i][0]);
                 }

            }
        }

        for(int i = 0; i < films.size();i++){
            std::cout<<films[i]<<": "<<roles[i]<<std::endl;
        }

        rFile.close();
    }else{
        std::cout<<"File is not found"<<std::endl;
    }






    return 0;
}
