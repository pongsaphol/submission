#ifndef __MASTERMIND_H
#define __MASTERMIND_H
#include <string>

void guess(std::string g, int& num_matched, int& num_misplaced);
void find_answer(int N, int K, int U);

#endif // __MASTERMIND_H
