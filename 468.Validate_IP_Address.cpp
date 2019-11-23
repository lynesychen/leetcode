class Solution {
public:
    string validIPAddress(string IP) {
        size_t pos = IP.find_first_of(".:");
		if (pos == string::npos)
			return "Neither";
		char sep = IP[pos];
		pos = 0;
		size_t str_max = (sep == '.') ? 3 : 4;
		size_t word_max = (sep == '.') ? 4 : 8;
		string protocol = (sep == '.') ? "IPv4" : "IPv6";
		int word_count = 0;
		size_t start_pos = 0;
		for (;start_pos < IP.size(); start_pos = ++pos) {
			int val = 0;
			size_t str_len = 0;
			for (; IP[pos] != sep && pos < IP.size(); ++pos, ++str_len) {
                bool range_check = isdigit(IP[pos]);
				if (sep != '.' && ((IP[pos] <= 'F' && IP[pos] >= 'A') || IP[pos] <= 'f' && IP[pos] >= 'a'))
					range_check = true;
				if (str_len > str_max || !range_check)
					return "Neither";
				if (sep == '.')
					val = val * 10 + IP[pos] - '0';
			}
			if (str_len == 0 || str_len > str_max)
				return "Neither";

			if (sep == '.' && ((val > 255) || (str_len == 3 && val < 100) || (str_len == 2 && val < 10)))
				return "Neither";
			word_count++;
			if (word_count == word_max)
				return (pos != IP.size()) ? "Neither" : protocol;
		}
		return "Neither";
    }
};
