#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Employee {
    public:
        int id;
        string name;
        string department;
        double salary;
        
        Employee(int i, string n, string d, double s) 
            : id(i), name(n), department(d), salary(s) {}
};

class CSVProcessor {
    private:
        vector<Employee> employees;
    
    public:
        void readFromFile(const string& filename) {
            ifstream file(filename);
            if (!file.is_open()) {
                throw runtime_error("Cannot open file: " + filename);
            }
            
            employees.clear();
            string line;
            
            // Skip header
            getline(file, line);
            
            while (getline(file, line)) {
                if (line.empty()) continue;
                
                stringstream ss(line);
                string token;
                vector<string> fields;
                
                while (getline(ss, token, ',')) {
                    fields.push_back(token);
                }
                
                if (fields.size() >= 4) {
                    int id = stoi(fields[0]);
                    string name = fields[1];
                    string dept = fields[2];
                    double salary = stod(fields[3]);
                    employees.push_back(Employee(id, name, dept, salary));
                }
            }
            file.close();
            cout << "Loaded " << employees.size() << " employees from " << filename << endl;
        }
        
        void generateReport(const string& outputFile) {
            ofstream out(outputFile);
            if (!out.is_open()) {
                throw runtime_error("Cannot create report file");
            }
            
            out << "EMPLOYEE REPORT\n";
            out << string(60, '=') << "\n";
            out << "ID,NAME,DEPARTMENT,SALARY\n";
            
            double totalSalary = 0;
            for (const auto& emp : employees) {
                out << emp.id << "," << emp.name << "," 
                    << emp.department << "," << emp.salary << "\n";
                totalSalary += emp.salary;
            }
            
            out << string(60, '-') << "\n";
            out << "TOTAL EMPLOYEES," << employees.size() << "\n";
            out << "AVERAGE SALARY," << (employees.empty() ? 0 : totalSalary / employees.size()) << "\n";
            out.close();
            
            cout << "Report generated: " << outputFile << endl;
        }
        
        void displaySummary() {
            cout << "\n=== Employee Summary ===" << endl;
            cout << "Total Employees: " << employees.size() << endl;
            
            double total = 0;
            for (const auto& emp : employees) total += emp.salary;
            cout << "Average Salary: $" << (employees.empty() ? 0 : total / employees.size()) << endl;
        }
};

int main() {
    // Create sample CSV data
    ofstream csvFile("employees.csv");
    csvFile << "ID,Name,Department,Salary\n";
    csvFile << "101,Arjun,Engineering,75000\n";
    csvFile << "102,Priya,Marketing,65000\n";
    csvFile << "103,Rahul,Engineering,82000\n";
    csvFile << "104,Sneha,HR,58000\n";
    csvFile << "105,Vikram,Sales,71000\n";
    csvFile.close();
    
    try {
        CSVProcessor processor;
        processor.readFromFile("employees.csv");
        processor.displaySummary();
        processor.generateReport("employee_report.txt");
        
        // Read and display the generated report
        cout << "\n=== Generated Report ===" << endl;
        ifstream report("employee_report.txt");
        string line;
        while (getline(report, line)) {
            cout << line << endl;
        }
        report.close();
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
