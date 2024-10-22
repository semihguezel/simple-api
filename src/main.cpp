#include "crow_all.h"
#include <vector>
#include <mutex>
#include <cstdlib>

std::vector<std::string> notes;
std::mutex notes_mutex;

int main()
{
    crow::SimpleApp app;

    // Ortam değişkenlerinden yapılandırma ayarlarını al
    const char* port_str = std::getenv("APP_PORT");
    uint16_t port = port_str ? static_cast<uint16_t>(std::stoi(port_str)) : 9080;

    const char* message = std::getenv("APP_MESSAGE");
    if (!message) {
        message = "Merhaba Dünya!";
    }

    // /hello endpoint'i
    CROW_ROUTE(app, "/hello")
    ([message](){
        return std::string(message);
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

    app.port(port).multithreaded().run();
}
