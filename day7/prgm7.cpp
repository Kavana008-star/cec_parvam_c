#include<iostream>
#include<string>
#include<vector>
#include<algorithm>    
using namespace std;
template<typename T>
class scoremanager {
    private:
    vector<T> scores;
    public:
    void addScore(T score){
        scores.push_back(score);
    }
    T getAverage() const {
        if(scores.empty()) return T();
        T sum = 0;
       for (T score : scores) sum += score;
        return sum / scores.size();
    }
    T getHighest() {
        return *max_element(scores.begin(), scores.end());
    }
    T getLowest() {
        return *min_element(scores.begin(), scores.end());
    }
    void displayScores() const {
        cout << "Scores: ";
        for (T score : scores) {
            cout << score << " ";
        }
        cout << endl;
    }
};
int main(){
    scoremanager<int> mathScore;
    mathScore.addScore(85);
    mathScore.addScore(92);
    mathScore.addScore(78);
    mathScore.addScore(88   );
    mathScore.addScore(95);
    cout<<"Math Scores:"<<endl;
    mathScore.displayScores();
    cout<<"Average: "<<mathScore.getAverage()<<endl;
    cout<<"Highest: "<<mathScore.getHighest()<<endl;    
    cout<<"Lowest: "<<mathScore.getLowest()<<endl;
    cout<<"count: "<<mathScore.getCount()<<endl;
    scoremanager<double> scienceScore;
    scienceScore.addScore(89.5);
    scienceScore.addScore(94.2);        
    scienceScore.addScore(91.8);                        
    scienceScore.addScore(87.3);
    scienceScore.addScore(90.0);
    
}