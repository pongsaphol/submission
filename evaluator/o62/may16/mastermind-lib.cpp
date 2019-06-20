#include "mastermind-lib.h"

#include <iostream>
#include <map>
#include <vector>

#include <cassert>

using namespace std;

static const vector<vector<int>> max_n_for_uk
{
	{0, 0, 7, 5, 4, 3, 3, 2, 2, 2},
	{0, 0, 2, 3, 4, 3, 3, 2, 2, 2}
};
static int N {0}, K {0}, U {-1};
static string answer;
static bool correct {false};
static bool guess_after {false};
static bool format_error {false};
static int num_guesses {0};

static bool check_length_and_colors(const string& s)
{
	if (static_cast<int>(s.size()) != N)
		return false;
	for (char c: s)
		if ('1' > c or c > '0' + K)
			return false;
	return true;
}

void guess(string g, int& num_matched, int& num_misplaced)
{
	num_matched = num_misplaced = -1;
	if (correct) // guess after finding the answer
	{
		guess_after = true;
		return;
	}
	if (not check_length_and_colors(g)) // format error
	{
		format_error = true;
		return;
	}

	++num_guesses;
	num_matched = num_misplaced = 0;
	map<char,int> ma, mg;

	for (int i {0}; i < N; ++i)
	{
		if (answer[i] == g[i])
			++num_matched;
		else
		{
			++ma[answer[i]];
			++mg[g[i]];
		}
	}

	if (num_matched == N)
	{
		correct = true;
		return;
	}

	for (char c {'1'}; c <= '0' + K; ++c)
		num_misplaced += min(ma[c], mg[c]);
}


int main()
{
	cin >> N >> K >> U;
	cin >> answer;
	assert(1 <= N and N <= 7);
	assert(2 <= K and K <= 9);
	assert(U == 1 or U == 0);
	assert(N <= max_n_for_uk[U][K]);

	find_answer(N, K, U);

	if (format_error)
		cout << "Incorrect: guess format error" << endl;
	else if (guess_after)
		cout << "Incorrect: guessing after finding the answer" << endl;
	else if (not correct)
		cout << "Incorrect: returning before finding the answer" << endl;
	else
		cout << "Correct: guessed " << num_guesses << " time(s)" << endl;

	return 0;
}
