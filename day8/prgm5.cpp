#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Logger {
    private:
        ofstream logFile;
        string getTimestamp() {
            time_t now = time(nullptr);
            char buf[20];
            strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
            return string(buf);
        }
    
    public:
        Logger(const string& filename) {
            logFile.open(filename, ios::app);
            if (!logFile.is_open()) {
                throw runtime_error("Cannot open log file: " + filename);
            }
            log("LOGGER STARTED");
        }
        
        void log(const string& message) {
            logFile << "[" << getTimestamp() << "] " << message << endl;
            cout << "[LOG] " << message << endl;
        }
        
        void error(const string& message) {
            logFile << "[ERROR][" << getTimestamp() << "] " << message << endl;
            cerr << "[ERROR] " << message << endl;
        }
        
        ~Logger() {
            try {
                log("LOGGER SHUTDOWN");
                logFile.close();
            } catch (...) {
                // Destructor should not throw
            }
        }
};

int main() {
    try {
        Logger logger("application.log");
        
        logger.log("Application started successfully");
        logger.log("User 'admin' logged in");
        logger.log("Processing payroll data...");
        
        // Simulate an operation that might fail
        int choice = 2;
        if (choice == 1) {
            logger.log("Payroll processed for 150 employees");
        } else {
            logger.error("Failed to process payroll: Invalid department code");
        }
        
        logger.log("Application shutting down gracefully");
        
        // Read back the log file
        cout << "\n=== Log File Contents ===" << endl;
        ifstream readLog("application.log");
        string line;
        while (getline(readLog, line)) {
            cout << line << endl;
        }
        readLog.close();
        
    } catch (const exception& e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }
    return 0;
}