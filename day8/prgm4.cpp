#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class ConfigReader {
    private:
        map<string, string> config;
    
    public:
        bool load(const string& filename) {
            ifstream file(filename);
            if (!file.is_open()) {
                cerr << "Error: Could not open " << filename << endl;
                return false;
            }
            
            string line;
            while (getline(file, line)) {
                // Skip comments and empty lines
                if (line.empty() || line[0] == '#') continue;
                
                // Parse key=value format
                size_t pos = line.find('=');
                if (pos != string::npos) {
                    string key = line.substr(0, pos);
                    string value = line.substr(pos + 1);
                    config[key] = value;
                }
            }
            file.close();
            cout << "Loaded " << config.size() << " configuration settings." << endl;
            return true;
        }
        
        string get(const string& key, const string& defaultVal = "") {
            if (config.find(key) != config.end())
                return config[key];
            return defaultVal;
        }
        
        void display() {
            cout << "\n=== Configuration ===" << endl;
            for (const auto& [key, value] : config) {
                cout << key << " = " << value << endl;
            }
        }
};

int main() {
    // Create a config file
    ofstream configFile("app.config");
    configFile << "# Application Configuration" << endl;
    configFile << "app_name=StudentManager" << endl;
    configFile << "version=2.5" << endl;
    configFile << "max_students=500" << endl;
    configFile << "db_host=localhost" << endl;
    configFile << "db_port=3306" << endl;
    configFile << "debug_mode=false" << endl;
    configFile.close();
    
    // Read and use config
    ConfigReader config;
    if (config.load("app.config")) {
        config.display();
        cout << "\n=== Using Config Values ===" << endl;
        cout << "Application : " << config.get("app_name") << endl;
        cout << "Max Students: " << config.get("max_students") << endl;
        cout << "DB Host     : " << config.get("db_host") << endl;
        cout << "DB Port     : " << config.get("db_port") << endl;
        cout << "Theme (default): " << config.get("theme", "light") << endl;
    }
    return 0;
}