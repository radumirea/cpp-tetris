#include "Repository.h"

void Repository::save(const Score & score) {
	auto found = std::find_if(scores.begin(), scores.end(), [score](const Score & score1) {
		return score.getName() == score1.getName();
	});
	if (found != scores.end()) {
		throw RepoException{ "Element already exists" };
	}
	scores.push_back(score);
}

void Repository::update(const Score & score) {
	auto found = std::find_if(scores.begin(), scores.end(), [score](const Score & score1) {
		return score.getName() == score1.getName();
	});
	if (found == scores.end()) {
		throw RepoException{ "Element does not exist" };
	}
	(*found).setScore(score.getScore());
}

const Score & Repository::find(const std::string & name) const {
	auto found = std::find_if(scores.begin(), scores.end(), [&](const Score& s) {
		return s.getName() == name;
	});
	if (found == scores.end()) {
		throw RepoException{ "Element does not exist" };
	}
	return *found;
}

const std::vector<Score>& Repository::all() const {
	return this->scores;
}

void RepoFile::loadFromFile() {
	std::ifstream in(fileName);
	if (!in.is_open()) { 	
		throw RepoException("Unable to open file: " + fileName);
	}
	while (!in.eof()) {
		std::string name;
		in >> name;
		int score;
		in >> score;
		if (in.eof()) {	
			break;
		}
		Score s{name,score};
		Repository::save(s);
	}
	in.close();
}

void RepoFile::saveToFile() {
	std::ofstream out(fileName);
	for (auto& s : all()) {
		out << s.getName();
		out << std::endl;
		out << s.getScore();
		out << std::endl;
	}
	out.close();
}