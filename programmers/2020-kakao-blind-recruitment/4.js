// 4. 가사 검색

const Node = function () {
	this.isEnd = false;
	this.children = new Map();
	this.cnt = 0;
};

const Trie = function () {
	this.root = new Node();

	this.insert = function (str, tNode = this.root) {
		while (str.length !== 0) {
			tNode.cnt += 1;
			if (!tNode.children.has(str[0])) {
				tNode.children.set(str[0], new Node());
			}
			tNode = tNode.children.get(str[0]);
			str = str.substr(1);
		}
		tNode.isEnd = true;
	};

	this.search = function (str, tNode = this.root) {
		if (str.length === 0) return true;
		if (!tNode.children.has(str[0])) return false;
		return this.search(str.substr(1), tNode.children.get(str[0]));
	};

	this.searchCnt = function (str, tNode = this.root) {
		if (str.length === 0) return tNode.cnt;
		if (!tNode.children.has(str[0])) return 0;
		return this.searchCnt(str.substr(1), tNode.children.get(str[0]));
	};
};

const revString = (str) => {
	const _str = str.split("").reverse().join("");
	return _str;
};

function solution(words, queries) {
	var answer = [];
	const trie = Array.from(new Array(10001), () => new Trie());
	const revTrie = Array.from(new Array(10001), () => new Trie());

	for (const word of words) {
		trie[word.length].insert(word);
		revTrie[word.length].insert(revString(word));
	}

	for (let query of queries) {
		if (query[0] === "?") {
			query = revString(query);
			answer.push(
				revTrie[query.length].searchCnt(query.replace(/\?/g, ""))
			);
		} else {
			answer.push(
				trie[query.length].searchCnt(query.replace(/\?/g, ""))
			);
		}
	}

	return answer;
}
