class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // For Truck P
        int pickP = 0;
        int travelP = 0;
        int lastHouseP = 0;
        // For Truck G
        int pickG = 0;
        int travelG = 0;
        int lastHouseG = 0;
        // For Truck M
        int pickM = 0;
        int travelM = 0;
        int lastHouseM = 0;

        // Now travel to the street of the house
        for (int i = 0; i < garbage.size(); i++) {
            string currHouse = garbage[i];
            // now let see that into the current house, which type of the
            // garbage it have
            for (int j = 0; j < currHouse.length(); j++) {
                char garbageType = currHouse[j];
                if (garbageType == 'P') {
                    pickP++;
                    // yaha tak toh mera truck pakka aaya hai, toh store it
                    lastHouseP = i;
                }
                if (garbageType == 'G') {
                    pickG++;
                    lastHouseG = i;
                }
                if (garbageType == 'M') {
                    pickM++;
                    lastHouseM = i;
                }
            }
        }
        // Now lets clacluate the travel time for P
        for(int i = 0; i < lastHouseP;i++){
            travelP += travel[i];
        }
        for(int i = 0;i < lastHouseG;i++){
            travelG += travel[i];
        }
        for(int i = 0;i < lastHouseM;i++){
            travelM += travel[i];
        }

        int TotalPickTime = pickP + pickM + pickG;
        int TotalTravelTime = travelP + travelG + travelM;

        int TotalTime = TotalPickTime + TotalTravelTime;
        return TotalTime;
    }
};