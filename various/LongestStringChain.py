'''
Longest String Chain

	Given a list of words, each word consists of English lowercase letters.

	Let's say word1 is a predecessor of 
	word2 if and only if we can add exactly
	one letter anywhere in word1 to make it 
	equal to word2.  For example, "abc" is a 
	predecessor of "abac".

	A word chain is a sequence of words 
	[word_1, word_2, ..., word_k] with k >= 1, 
	where word_1 is a predecessor of word_2, 
	word_2 is a predecessor of word_3, and so on.

	Return the longest possible length of a 
	word chain with words chosen from the given 
	list of words.

APPROACH ->
	1)Instead of adding a character, 
	try deleting a character to form a 
	chain in reverse.
	2)For each word in order of length, for each 
	word2 which is word with one character removed, 
		>>> length[word2] = max(length[word2], length[word] + 1).

links = youtube.com/watch?v=zqe_zIkyVGQ

'''

# Python

from collections import defaultdict
from itertools import combinations as cbn
len = len

class Solution:
	score = []
	edges = [[]]
	
	def longest(self ,i:int) -> int:
		if self.score[i] > 0:# dynamic
			return self.score[i]
		self.score[i] = 1
		for e in self.edges[i]:
			self.score[i] = max(self.score[i] ,self.longest(e)+1)
		return self.score[i]
			
	def longestStrChain(self, words: List[str]) -> int:
		self.edges = [[] for _ in range(len(words))]
		self.score = [0 for _ in range(len(words))]
		words_pos = defaultdict(lambda : -1)
		for i, w in enumerate(words):
			words_pos[w] = i
			
		for i ,w in enumerate(words):
			if len(w) == 1:continue
			for c in cbn(w ,len(w)-1):
				s = "".join(c)
				if words_pos[s] != -1:
					self.edges[words_pos[s]].append(i)
		# print(self.edges ,words_pos ,sep = "\n")
		ans = 0
		for i in range(len(words)):
			ans = max(ans ,self.longest(i))
			# print(i ,words[i] , ans)
		return ans


# C++

class Solution {
vector<vector<int>> edges;
vector<int> score;
int longest(int v) {
    if(score[v] > 0) {
        return score[v];
    }
    score[v] = 1;
    for(int b : edges[v]) { // O(M) = O(N*L)
        score[v] = max(score[v], longest(b) + 1);
    }
    return score[v];
}
public:    //  O(N*L^2)
    int longestStrChain(vector<string>& words) {
        const int n = words.size();
        edges.clear();
        edges.resize(n);
        score.clear();
        score.resize(n);
        unordered_map<string, int> his_position;
        for(int i = 0; i < n; i++) {  // O(N*L)
            his_position[words[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            string s = words[i];
            for(int j = 0; j < (int) s.length(); j++) {
                string maybe = s.substr(0, j) + s.substr(j+1); // O(N*L^2)
                auto it = his_position.find(maybe);
                if(it == his_position.end()) {
                    continue;
                }
                edges[it->second].push_back(i);
            }
        }
        int answer = 0;
        for(int i = 0; i < n; i++) {
            answer = max(answer, longest(i));
            // cout << longest(i) << endl;
        }
        return answer;
    }
};