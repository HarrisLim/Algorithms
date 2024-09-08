class Solution {
public:
    string convertDateToBinary(string date) {
        vector<int> binary;
        istringstream iss(date);
        string temp="", ret="";

        // split string by -
        while(getline(iss, temp, '-'))
            binary.push_back(stoi(temp));

        for(int i=0; i<3; i++)
        {
            temp = "";
            while(binary[i]!=0)
            {
                temp += to_string(binary[i] % 2);
                binary[i] /= 2;
            }
            reverse(temp.begin(), temp.end());
            ret += temp;
            if(i!=2) ret+="-";
        }
        return ret;
    }
};
