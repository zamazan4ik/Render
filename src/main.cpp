#include "CLI/CLI.hpp"

#include <nlohmann/json.hpp>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/random_layout.hpp>
#include <boost/graph/graphviz.hpp>

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using Graph = boost::adjacency_list<>;

[[nodiscard]] nlohmann::json parseJsonFile(const std::string& filename)
{
    std::ifstream inputFile(filename);
    nlohmann::json parsedJsonFile;
    inputFile >> parsedJsonFile;
    return parsedJsonFile;
}

[[nodiscard]] Graph createGraph(const nlohmann::json& jsonGraph)
{
    Graph g;

    std::unordered_map<int, boost::adjacency_list<>::vertex_descriptor> map;

    for (const auto& point : jsonGraph["points"])
    {
        boost::adjacency_list<>::vertex_descriptor v = boost::add_vertex(g);
        map[point["idx"]] = v;
    }

    for (const auto& edge : jsonGraph["lines"])
    {
        boost::add_edge(map[edge["points"][0]], map[edge["points"][1]], g);
    }

    return g;
}

int main(int argc, char* argv[])
{
    try
    {
        CLI::App app{"Simple graph render"};

        std::string inputFilename, outputFilename;
        app.add_option("-i,--input", inputFilename, "Input filename")->required();
        app.add_option("-o,--output", outputFilename, "Output filename")->required();

        CLI11_PARSE(app, argc, argv);

        const auto jsonGraph = parseJsonFile(inputFilename);

        const auto graph = createGraph(jsonGraph);

        std::ofstream dotfile(outputFilename);
        boost::write_graphviz(dotfile, graph);
    }
    catch (const std::exception& e)
    {
        std::cerr << "[main]: An exception was thrown: " << e.what();
    }
    catch (...)
    {
        std::cerr << "[main]: Some unknown exception was thrown";
    }
}
