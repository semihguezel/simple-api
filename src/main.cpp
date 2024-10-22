#include "crow_all.h"
#include <vector>
#include <mutex>

std::vector<std::string> notes;
std::mutex notes_mutex;

int main()
{
    crow::SimpleApp app;

    // /hello endpoint'i
    CROW_ROUTE(app, "/hello")
    ([](){
        return "Merhaba Dünya!";
    });

    // /notes endpoint'i (GET)
    CROW_ROUTE(app, "/notes")
    ([](){
        std::lock_guard<std::mutex> guard(notes_mutex);
        std::string all_notes;
        for(const auto& note : notes)
        {
            all_notes += note + "\n";
        }
        return all_notes;
    });

    // /notes endpoint'i (POST)
    CROW_ROUTE(app, "/notes").methods("POST"_method)
    ([](const crow::request& req){
        std::lock_guard<std::mutex> guard(notes_mutex);
        notes.push_back(req.body);
        return "Not eklendi.";
    });

    app.port(9080).multithreaded().run();
}
