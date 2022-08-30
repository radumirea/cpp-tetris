#pragma once

#include "Repository.h"

class Service {

private:
	Repository & repo;

public:
	Service(Repository& repo) noexcept : repo{ repo } {};
	~Service() = default;

	void saveScore(const std::string& name, const int score);
	void updateScore(const std::string& name, const int score);
	const Score& find(const std::string &name) const;
	const std::vector<Score>& all() const;
	const std::vector<Score> sortScore();
};

