#include "Service.h"

void Service::saveScore(const std::string & name, const int score) {
	try {
		repo.save(Score{ name,score });
	}
	catch (RepoException e) {
		if(score>repo.find(name).getScore())
			updateScore(name, score);
	}
}

void Service::updateScore(const std::string & name, const int score) {
	repo.update(Score{ name,score });
}

const Score & Service::find(const std::string & name) const {
	return repo.find(name);
}

const std::vector<Score>& Service::all() const {
	return repo.all();
}

const std::vector<Score> Service::sortScore() {
	std::vector<Score> sortedSc = all();
	std::sort(sortedSc.begin(), sortedSc.end(), [] (const Score& sc1, const Score& sc2){
		return sc1.getScore() > sc2.getScore();
	});
	return sortedSc;
}
