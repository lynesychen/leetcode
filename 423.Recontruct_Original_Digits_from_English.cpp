class Solution {
public:
    string originalDigits(string s) {
        map<char, int> myMap{
            {'g', 8}, {'x', 6}, {'u', 4}, {'w', 2}, {'z', 0}, 
            {'f', 5}, {'h', 3}, {'s', 7}, {'o', 1}, {'i', 9}
        };
        vector<int> numbers(10, 0);
        string res;

        for (auto p: myMap) {
            numbers[p.second] = count(s.begin(), s.end(), p.first);
        }

        numbers[5] -= numbers[4];
        numbers[3] -= numbers[8];
        numbers[7] -= numbers[6];
        numbers[1] -= (numbers[0] + numbers[2] + numbers[4]);
        numbers[9] -= (numbers[5] + numbers[6] + numbers[8]);

        for (int i = 0; i < 10; i++) {
            while(numbers[i] > 0) {
                res += ('0' + i);
                numbers[i]--;
            }
        }

        return res;
    }
};
