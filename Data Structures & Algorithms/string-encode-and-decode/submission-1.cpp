class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string encoded_string = "";
        for(int i = 0 ; i < n; i++){
            encoded_string += to_string(strs[i].size()) + '#' + strs[i];
        }
        
        cout << encoded_string << "\n";
        return encoded_string;
        
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> decoded_string;
        int i = 0 ;
        while(i < n)
        {
            int j = i;
            int l = 0;
            while (s[j] != '#') {
                l = l * 10 + (s[j] - '0');
                j++;
            }
            decoded_string.push_back(s.substr(j + 1, l));
            i = j + 1 + l;
        }

        return decoded_string;
    }
};
