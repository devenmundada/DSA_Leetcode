class Solution {
public:
    int CountDevices(string &binary) {
        int count = 0;
        for (int b = 0; b < binary.size(); b++) 
            count += binary[b] - '0';
            return count;
    }

    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;
        // for (int row = 0; row < bank.size(); row++) 
        for(auto row : bank)
            // devices.push_back(CountDevices(bank[row]));
            devices.push_back(CountDevices(row));
        
        int beams = 0;

        for (int i = 0; i < devices.size(); i++) {
            int j = i + 1;
            while (j < devices.size()) {
                beams += devices[i] * devices[j];

                if (devices[j] == 0)
                    j++;

                else
                    break;
            }
        }
        return beams;
    }
};