class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        int len = s.size();
        int n = words.size();
        int wordSize = words[0].size();
        int windowSize = wordSize * n;

        // Try all possible starting offsets
        for (int i = 0; i < wordSize; i++) {
            int start = i;
            int right = i;
            unordered_map<string, int> curr;
            int count = 0; // Tracks how many valid words are currently in our window

            while (right + wordSize <= len) {
                // Pull the next word from the right side
                string word = s.substr(right, wordSize);
                right += wordSize;

                if (freq.count(word)) {
                    curr[word]++;
                    count++;

                    // If we have too many instances of 'word', shrink window from the left
                    while (curr[word] > freq[word]) {
                        string leftWord = s.substr(start, wordSize);
                        curr[leftWord]--;
                        count--;
                        start += wordSize;
                    }

                    // If the number of matched words equals total words, we found a valid index
                    if (count == n) {
                        ans.push_back(start);
                    }
                } else {
                    // Invalid word encountered: completely reset the window
                    curr.clear();
                    count = 0;
                    start = right;
                }
            }
        }
        return ans;
    }
};