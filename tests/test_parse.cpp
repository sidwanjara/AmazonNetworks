#include "catch2/catch_test_macros.hpp"

#include "../includes/graph.hpp"

#include "../includes/utils.hpp"

using namespace std;

TEST_CASE("Parse Test Split Line") {
   string line = "2769                     18   ";
    pair<int, int> user = splitLine(line);
    pair<int, int> ans;
    ans.first = 2769;
    ans.second = 18;

    REQUIRE(user == ans);
}

TEST_CASE("Parse Test Split Line 2") {
    string line = "  2769   20   ";
    pair<int, int> user = splitLine(line);
    pair<int, int> ans;
    ans.first = 2769;
    ans.second = 20;

    REQUIRE(user == ans);
}

TEST_CASE("Constructor Adjacency Matrix 1") {
    string file = "../test_file.txt";
    Graph g(file);

    vector<vector<int>> expected = {
        {4, 5},
        {0, 2, 4, 5},
        {0, 11, 13},
        {63, 64},
    };


    REQUIRE(expected == g.getAdjacent());
}
