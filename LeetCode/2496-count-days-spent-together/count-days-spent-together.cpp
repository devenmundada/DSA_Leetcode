class Solution {
public:

    int toDay(string date){
        int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));

        for(int i = 0;i < month - 1;i++){
            day += months[i];
        }
        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        string start = max(arriveAlice,arriveBob);
        string end = min(leaveAlice,leaveBob);

        if(start > end){
            return 0;
        }
        int s = toDay(start);
        int e = toDay(end);
        
        return (e - s + 1);
    }
};