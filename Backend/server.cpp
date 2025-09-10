#include "crow_all.h"
#include <vector>
#include <string>

// Structure to store patient info
struct Patient {
    std::string name;
    int age;
};

// In-memory storage for patients
std::vector<Patient> patients;

int main() {
    crow::SimpleApp app;  // Create Crow application

    // POST endpoint to add a patient
    CROW_ROUTE(app, "/add_patient").methods(crow::HTTPMethod::Post)(
        [](const crow::request& req){
            auto body = crow::json::load(req.body);
            if (!body) return crow::response(400, "Invalid JSON");

            std::string name = body["name"].s();
            int age = body["age"].i();

            patients.push_back({name, age});
            return crow::response(200, "Patient added successfully");
        }
    );

    // GET endpoint to get all patients
    CROW_ROUTE(app, "/get_patients")(
        []{
            crow::json::wvalue result;
            for (size_t i = 0; i < patients.size(); i++) {
                result[i]["name"] = patients[i].name;
                result[i]["age"] = patients[i].age;
            }
            return result;
        }
    );

    // Start the server on port 18080
    app.port(18080).multithreaded().run();
}
